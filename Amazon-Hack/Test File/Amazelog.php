<html>
<head>
<title>:::: ::</title>
</head>
<body>
	<?php

		set_time_limit (0);
		$address = 'localhost';//'192.168.1.93';
		$port = 4000; 
			// Create the socket
			if(($sockd = socket_create(AF_INET, SOCK_STREAM,SOL_TCP))<1)
			die("Unable to create socket:" . socket_strerror(socket_last_error()));
		else
			echo "Socket created ...\n";
	 
			if(socket_connect($sockd,$address,$port) == FALSE)
					die("Unable to connect:" . socket_strerror(socket_last_error()));
		else
			echo "Socket connected ...\n";
	 
			$buffer =" This is my buffer";
	 
		class data
		{
			var $b = 60;
			var $string ="Helloooo";
		}
		$obj1 = new data(); 

		//$obj1 = "skjghkjdshghsghdskjghlshgdshgdshlghslhlgsjlglglsdlgdslgdslglshdglds"
		echo "serialized object : " . serialize($obj1) . "\n";
			//if(socket_send($sockd, $buffer,1024,MSG_WAITALL) == false))
		//if (false != ($bytes = socket_send($sockd, $buffer, 1024, MSG_WAITALL)))
		if(($bytes=socket_send($sockd,$buffer,1024, MSG_WAITALL))==false)
		{
					die("Unable to connect:" . socket_strerror(socket_last_error()));
		}
		else
		{
			echo "$buffer \n";
			echo "sent $bytes bytes from socket_send(). Closing socket...";
		}
			unset($obj1);
	 
		  //if(($buffer = socket_read($sockd, 1024)) == FALSE)
					//die("Unable to read from socket:" . socket_strerror(socket_last_error()));
	 
			socket_close($sockd);
	 ?>
</body>
</html>

