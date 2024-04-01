module main

import net

fn main() {
	mut sock := net.listen_tcp(net.AddrFamily.ip, "127.0.0.1:1337", net.ListenOptions{})!

	for {
		conn := sock.accept() or { return }

		mut buf := []u8{len: 4096}
		n := conn.read(mut buf)!
		buf.trim(n)

		println(buf.bytestr())
	}
}