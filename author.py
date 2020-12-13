"""
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 """
import os

comment = '"""\n *\n * Author:  Juarez Paulino(coderemite)\n * Email: juarez.paulino@gmail.com\n *\n """'

txt_list = []
for dirpath, dirnames, filename in os.walk('.'):
    for filename in filename:
        if not filename.endswith('.py'):
            continue

        # create full path
        txtfile_full_path = os.path.join(dirpath, filename)
        with open(txtfile_full_path, 'r+') as f:
            content = f.read()
            print(filename)
            f.seek(0, 0)
            f.write(comment + '\n' + content)
