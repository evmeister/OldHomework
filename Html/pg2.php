<html>
<body>
<?php
	$number1=$_POST["number1"];
	$number2=$_POST["number2"];
	$number3=$_POST["number3"];
	$number4=$number1 * $number2;

	if($number3 == $number4)
		{
		echo $number1 . "*" . $number2 . "=" . $number3 . "<br/>" . "Good! You have brought honor to your family.";
		}
	else
		{
		echo $number1 . "*" . $number2 . "=" . $number4 . "<br/>" . "Incorrect. Go practice more to restore your honor.";
		}
?>
<form method="POST" action="pg1.php">
	<input type="submit" value="Try Again"/>
</form>
<body/>
<html/>
