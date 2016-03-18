port = dotNetObject "System.IO.Ports.SerialPort" "COM3" 115200
port.parity = port.parity.none
port.databits = 8
port.stopbits = port.stopbits.one
port.handshake= port.handshake.RequestToSend

 rollout MinImu "MinImuToMax"  width:90 height:150
 (
dotNetControl dn_labelPR "System.Windows.Forms.Label" text:"seconds" pos:[20,10] width:50 height:20
dotNetControl textboxctrl "System.Windows.Forms.TextBox" pos:[20,30] width:50 height:30
button Frames "Frames" width:50 height:20 
button Start "Start" width:50 height:20
button Stop "Stop" width:50 height:20
	 
on Frames pressed do 
 ( 
 	finSec = textboxctrl.text as integer
	finFrame = finSec * 25
	 animationRange = interval 0 finFrame 
	
 )
 
 on Start pressed do --the button
 ( 

port.Open()
	 
 	finSec2 = textboxctrl.text as integer
	finFrame2 = finSec2 * 25	 

for i= 1 to finFrame2 do

 (
	      	 
 rotValue = port.ReadLine() as string
	 --encontramos las letras
	 r = findstring rotValue "r"
	 p = findstring rotValue "p"
	 y = findstring rotValue "y"
	 en = findstring rotValue "e"
	 --las convertimos en numeros float
	 r2 = r as float
	 p2 = p as float
	 y2 = y as float
	 en2 = en as float
	 --asignamos limites del substring	 
	 r3 = r2 + 1
	 p3 = p2 - 2
	 p4 = p2 + 1
	 y3 = y2 - p4 
	 y4 = y2 + 1
	 en3 = en2 - y4
	 --aislamos roll pitch yaw
	 roll = substring rotValue r3 p3
	 pitch = substring rotValue p4 y3
	 yaw = substring rotValue y4 en3
     --convertimos roll pitch yaw en numeros float
	 rollValue = roll as float
	 pitchValue = pitch as float
	 yawValue = yaw as float
	 --imprimimos roll pitch yaw 
	--print rollValue
	--print pitchValue
	--print yawValue
	 --enviamos valores a la caja
	 if rollValue != undefined then
 (
 	$caja.rotation.controller.x_rotation = rollValue	
 )
 	 if pitchValue != undefined then
 (
 	$caja.rotation.controller.y_rotation = pitchValue *-1	
 )
 	 if yawValue != undefined then
 (
 	$caja.rotation.controller.z_rotation = yawValue *-1	
 )

 completeRedraw()
 sliderTime += 1

 )
 )
 
 on Stop pressed do
 (
	 port.Close()
 
 )
 
 )
 
createdialog MinImu
 