#include <bits/stdc++.h>

namespace oaht {

using std::size_t;

enum class node_state { FREE, IN_USE, ERASED };

template <typename _Key, typename _Value> struct node {
  _Key key;
  _Value value;
  node_state state = node_state::FREE;
};

template <typename _Key, typename _Value, typename _Hash = std::hash<_Key>>
class HashMap {
public:
  HashMap(size_t capacity) : capacity(capacity), size(0) {
    nodes = new node<_Key, _Value>[capacity];
    for (size_t i = 0; i < capacity; i++) {
      nodes[i] = node<_Key, _Value>();      
    }
  }

  HashMap() : HashMap(3) {}

  size_t count(const _Key &key) const {
    size_t index = getIndex(key, capacity);

    for (size_t d = 0; d < capacity; d++) {
      if (nodes[index].state == node_state::FREE) return false;
      if (nodes[index].state == node_state::IN_USE && nodes[index].key == key) return true;
      index++;
      if (index == capacity)index = 0;
    }
    return false;
  }

  void erase(const _Key &key) {
    size_t index = getIndex(key, capacity);
    for (size_t d = 0; d < capacity; d++) {
      if (nodes[index].state == node_state::FREE) break;
      if (nodes[index].state == node_state::IN_USE && nodes[index].key == key) {
        nodes[index].state = node_state::ERASED;
        return;
      };
      index++;
      if (index == capacity)index = 0;
    }
    throw std::logic_error("Unexpected case.");
  }
  
  _Value &operator[](const _Key &key) {
    if ((size << 1) > capacity) rehash();
    size_t index;
    bool result = put(key, index, nodes, capacity);
    if (result) size++;
    return nodes[index].value;
  }

  ~HashMap() { delete[] nodes; }

private:
  size_t getIndex(const _Key &key, size_t size) const {
    return (h(key) * 22543LL) % size;
  }

  void rehash() {
    size_t n_capacity = (capacity << 1);
    node<_Key, _Value> *n_nodes = new node<_Key, _Value>[n_capacity];
    for (size_t i = 0; i < n_capacity; i++) {
      n_nodes[i] = node<_Key, _Value>();
    }
    for (size_t i = 0; i < capacity; i++) {
      if (nodes[i].state == node_state::IN_USE) {
        size_t index;
        put(nodes[i].key, index, n_nodes, n_capacity);
        n_nodes[index].value = nodes[i].value;
      }
    }
    delete[] nodes;
    nodes = n_nodes;
    capacity = n_capacity;
  }

  bool put(const _Key &key, size_t &index, node<_Key, _Value> *nodes, size_t nodes_length) {
    index = getIndex(key, nodes_length);
    for (size_t i = 0; i < nodes_length; i++) {
      if (nodes[index].state == node_state::FREE || nodes[index].state == node_state::ERASED) {
        nodes[index].key = key;
        nodes[index].state = node_state::IN_USE;
        return true;
      }
      if (nodes[index].key == key) return false;
      index++;
      if (index == nodes_length) index = 0;
    }
    throw std::logic_error("Unexpected case.");
  }
  size_t capacity;
  size_t size;
  node<_Key, _Value> *nodes;
  _Hash h;
};
} // namespace oaht

using namespace std;

int main(int argc, char *argv[]) {
  oaht::HashMap<int, int> hm;
  hm[1] = 5;
  hm[19942425] = 7;
  cout << hm.count(19942425) << endl;
  hm.erase(19942425);
  cout << hm.count(19942425) << endl;
  cout << hm[19942425] << endl;
  cout << hm.count(19942425) << endl;
  return 0;
}
