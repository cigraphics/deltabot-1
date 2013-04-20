#!/usr/bin/env python

#from urlparse import urlparse, parse_qs, parse_qsl
import urlparse
from subprocess import call
from BaseHTTPServer import BaseHTTPRequestHandler, HTTPServer
import os

call("/home/PiBits/ServoBlaster/servod")

class DeltaBotHTTPRequestHandler(BaseHTTPRequestHandler):
  def do_GET(self):
		url = self.path
		url = url.replace("/", "").replace("favicon.ico", "").replace("?", "")
		if url == "" :
			f = open('test.html')
			self.send_response(200)
			self.send_header('Content-Type', 'text/html')
			self.end_headers()
			self.wfile.write(f.read())
			f.close()
		else :
			self.send_response(200)
			self.send_header('Content-Type', 'text/html')
			self.end_headers()
			self.wfile.write('ok')
			data = dict(urlparse.parse_qsl(url))
			x = int(data["x"])
			y = int(data["y"])
			z = int(data["z"])
			list = {x,y,z}
			mx = max(list) + 1
			nx = 0
			ny = 0
			nz = 0
			for mx in range(1, mx) :
				if nx < x :
					nx = nx + 1
				if ny < y :
					ny = ny + 1
				if nz < z :
					nz = nz + 1
				os.system("/home/project/delta.o " + str(nx) + " " + str(ny) + " " + str(nz))
		return

def run():
	print('http server is starting...')
	server_address = ('0.0.0.0', 80)
	httpd = HTTPServer(server_address, DeltaBotHTTPRequestHandler)
	print('http server is running...')
	httpd.serve_forever()

if __name__ == '__main__':
    run()
