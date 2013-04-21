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
				if data["z"] == "mouse" :
					print("mouse")
				else :
					x = int(data["x"])
					y = int(data["y"])
					z = int(data["z"])
					list = {x,y,z}
					ma = max(list)
					nx = 0
					ny = 0
					nz = 0
					maZ = ma + 1
					for i in range(0, maZ) :
						if x == ma :
							maxx = x
						if y == ma :
							maxx = y
						if z == ma :
							maxx = z
						if maxx - x - i <= 0 and nx < x :
							nx = nx + 1
						if maxx - y - i <= 0 and ny < y :
							ny = ny + 1
						if maxx - z - i <= 0 and nz < z :
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
