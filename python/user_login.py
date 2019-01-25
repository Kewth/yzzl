'user login or register'
import sys
import leancloud as AV

def main():
    'Main function'
    AV.init('BXRMoB3y7fcc0qg4SjwCbXn5-gzGzoHsz', 'JewOaHO3M0OuHxDBTKaMvQCi')
    out = open('py_output', mode='w')
    if len(sys.argv) != 4:
        return 1
    user = AV.User()
    try:
        if sys.argv[3] == 'l':
            user.login(sys.argv[1], sys.argv[2])
        else:
            user.set_username(sys.argv[1])
            user.set_password(sys.argv[2])
            user.sign_up()
    except:
        return 2
    user.fetch()
    out.write('exp: {:d}\n'.format(user.get('exp')))
    return 1

sys.exit(main())
