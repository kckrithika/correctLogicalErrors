//#include <stdio.h>
//#include <stdlib.h>
#define YES 1
#define NO 0
#define UsageMesg "Usage: %s [-lwc] [filelist]\n"
#define OpenMesg "%s: %s: No such file or directory\n"
main(int argc, char *argv[])
{
	int characters, words, lines; /* count per file */
 	int tcharacters = 0, twords = 0, tlines = 0; /* count for all files */
	int ch, in_word, index, j, fileptr;
	int cflag = YES, wflag = YES, lflag = YES; /* default settings */
	FILE *fp;
	fp = stdin; /* default input */
	fileptr = argc; /* assuming no filenames as arguments */
	/* *** check for passed arguments - assume all flags appear before filelist *** */
	if (argc > 1)
 	{ 
		if (argv[1][0] == '-') /* any flags? */
 		{
			cflag = NO; /* if flag arguments have been passed then enable only */
 			wflag = NO; /* those options that have been selected */
 			lflag = NO;
 		}
 		for (index = 1; index < argc; index++) /* go through passed arguments */
 			if (argv[index][0] == '-') /* look to see if it is a flag */
 			{
				for (j = 1; j < strlen(argv[index]); j++) /* process the flag */
 					switch( argv[index][j] )
 					{
						case 'l' : lflag = YES; break; /* output line count */
						case 'w' : wflag = YES; break; /* output word count */
 						case 'c' : cflag = YES; break; /* output character count */
 						default : fprintf(stderr, UsageMesg, argv[0]);
 						exit(1);
 					}
 			}
 			else
 			{
 				fileptr = index;
 				break; /* remaining arguments are filenames */
			}
	}
	while (index < argc) /* perform actual counts of lines, words, and characters */
 	{
 		if ( fileptr != argc )
 			if ( (fp = fopen(argv[index], "r") ) == NULL )
 			{
 				fprintf(stderr, OpenMesg, argv[0], argv[index++]); /* can't read file */
 				continue;
			}
 		characters = words = lines = 0; /* zero counters and flag */
 		in_word = NO;
		while ( ( ch = getc(fp) ) != EOF ) /* process the current file */
		{
 			characters++; /* increment character count */
 			if ( ch == '\n') /* increment line count */
 				lines++;
 			if ((ch == ' ') || (ch == '\t') || (ch == '\n')) /* have whitespace */
 				in_word = NO;
 			else if (in_word == NO) /* increment word count */
 			{
 				in_word = YES;
 				words++;
 			}
 		}
 		if (lflag) printf(" %7ld", lines);
 			if (wflag) printf(" %7ld", words);
 				if (cflag) printf(" %7ld", characters);
 					if (argc != fileptr)
 						printf(" %s\n", argv[index]); /* print filename */
 					else
 						printf("\n");
 		fclose(fp); /* close current input file */
 		tcharacters += characters; /* update total counts for all files */
		twords += words;
 		tlines += lines;
 		index++;
	}
	if (argc - fileptr > 1) /* then have two or more files, so print out total count(s) */
 	{
 		if (lflag) printf(" %7ld", tlines);
 			if (wflag) printf(" %7ld", twords);
 				if (cflag) printf(" %7ld", tcharacters);
 					printf(" total\n");
 	}
 	exit(0); /* exit program - return status normal: successful execution */
}
