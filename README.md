# wifi-based-oscilloscope
here is a wifi based oscilliscope for remote monitoring of electrical equipment. it works reasonably well it based on a esp and mcp3008 chip in conjunction with lxardoscope software to view the signal.
it is reasonably accurate  and supports  upto  8 probes
 all you need to do is on the recieve computer create 4 virtual ports IE:
 
 socat -u udp-recv:1234 PTY,link=/dev/ttyS18,group=tty,mode=770  
 
 then simply connect lxardoscope to those virtual ports  to view the realtime osciliscope info from a remote device
 lxardoscope can be found here 
 https://sourceforge.net/projects/lxardoscope/
