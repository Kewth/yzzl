'update user'
import sys
import leancloud as AV

def main():
    'Main function'
    AV.init('BXRMoB3y7fcc0qg4SjwCbXn5-gzGzoHsz', 'JewOaHO3M0OuHxDBTKaMvQCi')
    get = open('py_input', mode='r')
    if len(sys.argv) != 3:
        return 1
    user = AV.User()
    try:
        user.login(sys.argv[1], sys.argv[2])
    except:
        return 2
    string = get.readline()
    user.set('exp', int(string[5:-1]))
    user.save()
    return 0

sys.exit(main())
