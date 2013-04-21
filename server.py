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
		self.send_response(200)
		self.send_header('Content-Type', 'text/html')
		self.end_headers()
		
		if url == "" :
			url = "index.html"
		
		if url.endswith(".html") :
			f = open(url)
			self.wfile.write(f.read())
			f.close()
		else :
			self.wfile.write('ok')
			if url == "reset" :
				os.system("/home/project/reset.o")
			else :
				data = dict(urlparse.parse_qsl(url))
				x = data["x"]
				y = data["y"]
				z = data["z"]
				os.system("/home/project/test.o " + x + " " + y + " " + z)
		return

def run():
	print('http server is starting...')
	server_address = ('0.0.0.0', 80)
	httpd = HTTPServer(server_address, DeltaBotHTTPRequestHandler)
	print('http server is running...')
	httpd.serve_forever()

if __name__ == '__main__':
    run()

