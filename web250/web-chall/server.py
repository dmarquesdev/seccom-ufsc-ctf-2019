#!/usr/bin/env python3

from http.server import HTTPServer, CGIHTTPRequestHandler

server = HTTPServer
handler = CGIHTTPRequestHandler
server_address = ('', 8085)
handler.cgi_directories = ['/app']

httpd = server(server_address, handler)

try:
    httpd.serve_forever()
except KeyboardInterrupt:
    httpd.socket.close()
except OSError:
    print('hello')