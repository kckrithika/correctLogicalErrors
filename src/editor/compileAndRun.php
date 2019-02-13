<?php
	$code = $_POST["code"];
	$file_code = fopen("code.c","w+");
	fwrite($file_code, $code);
	fclose($file_code);
	shell_exec("gcc -lm code.c 2> error.txt");
	$error = file_get_contents("error.txt");
	if(trim($error)=="")
	{
		$input = $_POST["input"];
		$file_in=fopen("input.txt","w+");
		fwrite($file_in,$input);
		fclose($file_in);
		$output = shell_exec("./a.out < input.txt");
		echo "Output: ".$output."<br>";
	}
	else
	{
		echo "Compiler error: <br>";
		echo $error;
	}
?>
