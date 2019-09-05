	for(int i=1;i<argc;i+=1){

		if (!strcmp("-v", argv[i]))
			die("dwm-"VERSION);
		else
			if (!strcmp("-h", argv[i]) || !strcmp("--help", argv[i]))
			    die(help());
		else
			if (!strcmp("-fn", argv[i])) /* font set */
			    fonts[0] = argv[++i];
		else
			if (!strcmp("-nb",argv[i])) /* normal background color */
			    colors[SchemeNorm][1] = argv[++i];
		else
			if (!strcmp("-nf",argv[i])) /* normal foreground color */
			    colors[SchemeNorm][0] = argv[++i];
		else
			if (!strcmp("-sb",argv[i])) /* selected background color */
			    colors[SchemeSel][1] = argv[++i];
		else
			if (!strcmp("-sf",argv[i])) /* selected foreground color */
				colors[SchemeSel][0] = argv[++i];
		else
			if (!strcmp("-sbr",argv[i])) /* selected border color */
				colors[SchemeSel][2] = argv[++i];
		else
			if (!strcmp("-nbr",argv[i])) /* normal border color */
				colors[SchemeNorm][2] = argv[++i];
		// else
		// 	if (!strcmp("-bpx", argv[i])) /* border pixels */
		// 		sscanf(argv [++i], "%u", (unsigned*)(&borderpx));
		else
			die(help());
	}
		// else if (!strcmp("-df", argv[i])) /* dmenu font */
		// 	dmenucmd[4] = argv[++i];
		// else if (!strcmp("-dnb",argv[i])) /* dmenu normal background color */
		// 	dmenucmd[6] = argv[++i];
		// else if (!strcmp("-dnf",argv[i])) /* dmenu normal foreground color */
		// 	dmenucmd[8] = argv[++i];
		// else if (!strcmp("-dsb",argv[i])) /* dmenu selected background color */
		// 	dmenucmd[10] = argv[++i];
		// else if (!strcmp("-dsf",argv[i])) /* dmenu selected foreground color */
		// 	dmenucmd[12] = argv[++i];
