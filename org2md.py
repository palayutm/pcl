with open('README.md', 'w') as fp:
    done, todo = [], []
    for line in open('README.org'):
        line = line.replace('*', '#').strip()
        if line.startswith('###'):
            line = line.replace('#', '').strip()
            if (line.startswith('TODO')):
                todo.append(line[4:])
            elif line.startswith('DONE'):
                done.append(line[4:])
        elif line.startswith('##'):
            if len(done) > 0:
                fp.write('\n- **DONE:** ' + ', '.join(done) + '\n\n')
            if len(todo) > 0:
                fp.write('\n- **TODO:** ' + ', '.join(todo) + '\n\n')
            done, todo = [], []
            fp.write(line + '\n')
        elif line.startswith('#'):
            fp.write(line + '\n----\n')
    if len(done) > 0:
        fp.write('\n- **DONE:** ' + ', '.join(done) + '\n\n')
    if len(todo) > 0:
        fp.write('\n- **TODO:** ' + ', '.join(todo) + '\n\n')
