<html>
<body>
<center>
<p>
Here are the numbers you entered:
</p>
</br>
<?php
	//This loop collects the numbers from the first page
	for($i=0;$i<5;$i++)
	{
		$entered[$i]=$_POST["guess$i"];
		echo $entered[$i] . " ";
	}
?>
</br>
<p>
And here are the correct numbers:
</p>
</br>
<?php
	srand();
	//This loop generates five random numbers
	for($i=0;$i<5;$i++)
	{
		$correct[$i]=rand(0,20);
		echo $correct[$i] . " ";
	}
	//This loop checks the guesses against the random numbers
	$counter=0;
	for($j=0;$j<5;$j++)
	{
		for($k=0;$k<5;$k++)
		{
			if($entered[$j]==$correct[$k])
			{
				$counter++;
			}
		}
	}
	//This will give an appropriate response to the compulsive gambler
	if($counter==5)
	{
		echo "</br>" . "As unlikely as it is, you have guessed " . $counter . "/5 lottery numbers. Good for you, now you can justify gambling more!";
	}
	else
	{
		echo "</br>" . "Total shocker; you only guessed " . $counter . "/5 lottery numbers. You could always try again. Always.";
	}
?>
</br>
<form method="POST" action="lottopg1.php">
	<input type="submit" value="Waste more money"/>
</form>
</center>
</body>
</html>
