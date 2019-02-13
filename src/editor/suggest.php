<?php
	
	function execute($script)
	{
		$cmd = "/home/gokul/pve1/bin/python -c \"".$script."\"";
		return shell_exec($cmd);
	}
	$code = $_POST["code"];
	$code_file = fopen("partial.c", "w+");
	fwrite($code_file, $code);
	fclose($code_file);
	$script = "import ASTProducer as a; a.produce(\\\"partial.c\\\")";
	$output = execute($script);
	$script = "import convertToNumber as c; c.convert(\\\"InputSequence.txt\\\")";
	$output = execute($script);
	$script = "import predictor as p; print(p.predict())";
	$json_suggestion = execute($script);
	echo $json_suggestion;
	/*$suggestion = json_decode($json_suggestion);
	$count = $suggestion->count;
	for($i=0; $i<$count; $i++)
	{
		echo $suggestion->$i."<br>";
	}*/
?>
