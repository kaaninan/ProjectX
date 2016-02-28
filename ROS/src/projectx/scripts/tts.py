#!/usr/bin/env python

import sys

if __name__ == '__main__':
    if len(sys.argv) > 1 and sys.argv[1] == '--help':
        print 'Usage: %s \'String to say.\''%sys.argv[0]
        print '       %s < file_to_say.txt'%sys.argv[0]
        print
        print 'Says a string. For a string on the command line, you must use quotes as'
        print 'appropriate. For a string on standard input, the command will wait for'
        print 'EOF before saying anything.'
        exit(-1)

    # Import after printing usage for speed.
    import rospy
    from sound_play.msg import SoundRequest
    from sound_play.libsoundplay import SoundClient

    if len(sys.argv) == 1:
        print 'Awaiting something to say on standard input.'

    # Ordered this way to minimize wait time.
    rospy.init_node('say', anonymous = True)
    soundhandle = SoundClient()
    rospy.sleep(1)

    voice = 'voice_kal_diphone'
    volume = 1.0

    if len(sys.argv) == 1:
        s = sys.stdin.read()
    else:
        s = sys.argv[1]

        if len(sys.argv) > 2:
            voice = sys.argv[2]

    print 'Saying: %s' % s
    print 'Voice: %s' % voice

    soundhandle.say(s, voice)
    rospy.sleep(1)