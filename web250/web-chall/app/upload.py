#!/usr/bin/env python3
import os
from cgi import FieldStorage, escape
from PIL import Image
from io import BytesIO

UPLOAD_DIR = './uploads/images'

form = FieldStorage()
error = False
try:
    image = form['image']
except KeyError:
    message = 'Image not found'
    error = True

if not error:
    filename = escape(image.filename)
    if filename:
        output_file = os.path.join(UPLOAD_DIR, filename)
        if os.path.dirname('.') not in os.path.dirname(output_file):
            message = 'Path traversal attempt detected!'
        else:
            try:
                bt = image.file.read()
                i = Image.open(BytesIO(bt))
                with open(output_file, 'wb') as f:
                    f.write(bt)
                message = 'File upload success, <a href="/uploads/images/{}">Click here to access</a>'.format(filename)
            except IOError:
                message = 'Only image files are supported!'
    
print("""\
Content-Type: text/html\n
<html>
<body>
   <p>{}</p>
</body>
</html>
""".format(message))