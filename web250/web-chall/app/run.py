#!/usr/bin/env python3

import os
import subprocess
from cgi import FieldStorage, escape

message = ''

form = FieldStorage()
legit = True

try:
    script = escape(form['script'].value)
    script = os.path.basename(script) # get rid of path traversal
except KeyError:
    message = "No Script found"
    legit = False


if legit and (script == 'run.py' or script == 'upload.py'):
    message = 'Illegal script'
    legit = False

injection_blacklist = ['/', '|', '{', '}', '\'', '"', '&', '`', ';', '(', ')', '$', '<', '>', '[', ']', '\\']

if legit:
    for c in script:
        if c in injection_blacklist:
            message = 'Illegal character'
            legit = False
            break
    script = 'app/' + script
    script = os.path.abspath(script)
    message = subprocess.Popen(['python3', script],
                stdout=subprocess.PIPE,
                stderr=subprocess.STDOUT).communicate()[0]

print("""\
Content-Type: text/html\n
<html>
<body>
   <p>{}</p>
</body>
</html>
""".format(message))