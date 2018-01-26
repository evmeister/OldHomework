###########################################################################
##################### README For Test Script ##############################
###########################################################################

This set of files are to be included in the same directory as the .sh files.

Use test_one.sh if you have written your programs to use the following call format:

	./algorithm size

e.g.
	./lru 10

Use test_sim.sh if you have written one file that uses the following call:

	./exe -algorithm size

e.g.
	./simulate -lru 10

For BOTH scripts, please modify the 'scriptDIR' variable to specify the 
working directory of the script file and accompanied reference files. If it
is in the same directory as your compiled programs, you may use './', 
otherwise I suggest using a full path from your home directory 
(e.g. ~/Documents/COEN177/..../).

You can then run the respective scripts as follows:

	/path/to/dir/test_one.sh exe

e.g.
	./test_one lru


	/path/to/dir/test_sim.sh exe alg

e.g.
	./test_sim.sh simulate lru

Please let me know if you have any further questions regarding the script.
