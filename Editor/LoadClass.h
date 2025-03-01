char Classes[64][5];
unsigned char ClassData[210][8];

unsigned char Priority0[64]; // Null
unsigned char Priority1[64]; // Standard
unsigned char Priority2[64]; // Mounted
unsigned char Priority3[64]; // Aquatic
unsigned char Priority4[64]; // Forest
unsigned char Priority5[64]; // Mechanical
unsigned char Priority6[64]; // Flying
unsigned char Priority7[64]; // Hovering
unsigned char Priority8[64]; // Undefined

long ClassNamesOffset;
long ClassOffset;

char ClassMovements[][16] = { "","Standard","Mounted","Aquatic","Forest","Mechanical","Flying","Hovering" };
char ClassActions[][20] = { "Default","Caster","Use Items","Fire Breath","Fire Breath 2","Fire Breath 3","Ice Breath","Fire Breath 4","Ice Breath 2", "Electric Breath","Machine Gun","Laser","Demon Blaze","Dark Dragon Mid","Dark Dragon Side" };
char ActionChances[][6] = { "100%","25%","50%","75%" };
char SpecialAttacks[][20] = { "None","150% Damage Crit","200% Damage Crit","Steal MP","Steal HP","Steal HP 2","Poison Chance","Sleep Chance","Sleep Chance 2","Death Chance" };
char SpecialChances[][6] = { "0%","25%","50%","75%" };
char DoubleChances[][16] = { "Default","Never","High","Level Bonus" };

unsigned char ClassAction = 255;
unsigned char ActionChance = 255;
unsigned char ClassSpecial = 255;
unsigned char SpecialChance = 255;

unsigned char BaseResistance;
unsigned char TwentyFiveResistance;
unsigned char FiftyResistance;
unsigned char TwentyFiveWeakness;

unsigned char ClassPromote[64];

void LoadClass(char *path,bool single=false){
	unsigned char r,c;
	FILE * fp = fopen(path,"rb");
	char in=0;

	int i;

	if (!single) {
		for (i = 0; i < 64; i++) {
			sprintf(Classes[i], "-");
			Priority0[i] = 0;
			Priority1[i] = 25;
			Priority2[i] = 0;
			Priority3[i] = 25;
			Priority4[i] = 25;
			Priority5[i] = 25;
			Priority6[i] = 25;
			Priority7[i] = 25;
			Priority8[i] = 0;
			if (i < 14) {
				ClassPromote[i] = i + 16;
			} else {
				ClassPromote[i] = 0xFF;
			}
		}
		for (i = 0; i < 210; i++) {
			for (int j = 0; j < 8; j++) {
				ClassData[i][j] = 0;
			}
		}
	}

	fseek(fp, 0x22F92, SEEK_SET);
	fscanf(fp, "%c", &r);
	if (r == 0x26) {
		NumClasses = 32;
		ExtendEquip = false;
	} else {
		NumClasses = 64;
		ExtendEquip = true;
	}

	/* table_PromotedClasses */
	if (NumClasses == 64) {
		fseek(fp, 0x16FE20, SEEK_SET);
		for (i = 0; i < 64; i++) {
			fscanf(fp, "%c", &(ClassPromote[i]));
		}
		fseek(fp, 0x16FAC0, SEEK_SET);
	} else {
		fseek(fp, 0x243AA, SEEK_SET);
	}

	/* table_AiPriority */
	for(i=0; i<NumClasses; i++){
		fscanf(fp,"%c",&r);
		Priority0[i] = r;
		Priority1[i] = r;
		Priority2[i] = r;
		Priority3[i] = r;
		Priority4[i] = r;
		Priority5[i] = r;
		Priority6[i] = r;
		Priority7[i] = r;
		Priority8[i] = r;
	}

	fseek(fp,0x203C0,SEEK_SET);
	fscanf(fp,"%c",&r);
	ClassNamesOffset = r;
	fscanf(fp,"%c",&r);
	ClassNamesOffset = ClassNamesOffset*256+r;
	fscanf(fp,"%c",&r);
	ClassNamesOffset = ClassNamesOffset*256+r;
	fscanf(fp,"%c",&r);
	ClassNamesOffset = ClassNamesOffset*256+r;

	MonsterNameOffset = ClassNamesOffset;

	if(MonsterNameOffset==0x25D6C)
		NumMonsters=73;
	else
		NumMonsters=146;

	fseek(fp,ClassNamesOffset,SEEK_SET);
	for(i=0; i<NumClasses; i++){
		fscanf(fp,"%c",&r);
		MonsterNameOffset+=r+1;
		for(int j=0; j<r; j++){
			if(single&&i!=select[mode]){
				fscanf(fp,"%c",&c);
				continue;
			}
			fscanf(fp,"%c",&(Classes[i][j]));
		}
		if(!single||i==select[mode])Classes[i][r]='\0';
	}

	fseek(fp, 0x211E2, SEEK_SET); //Base Damage Taken (100 is Default)
	fscanf(fp, "%c", &BaseResistance);
	fseek(fp, 0x211E3, SEEK_SET); //25% Resistance (75 is Default)
	fscanf(fp, "%c", &TwentyFiveResistance);
	fseek(fp, 0x211E4, SEEK_SET); //50% Resistance (50 is Default)
	fscanf(fp, "%c", &FiftyResistance);
	fseek(fp, 0x211E5, SEEK_SET); //25% Weakness (125 is Default)
	fscanf(fp, "%c", &TwentyFiveWeakness);

	fseek(fp,0x203C4,SEEK_SET);
	fscanf(fp,"%c",&r);
	ClassOffset = r;
	fscanf(fp,"%c",&r);
	ClassOffset = ClassOffset*256+r;
	fscanf(fp,"%c",&r);
	ClassOffset = ClassOffset*256+r;
	fscanf(fp,"%c",&r);
	ClassOffset = ClassOffset*256+r;

	fseek(fp,ClassOffset,SEEK_SET);
	for(i=0; i<NumClasses + NumMonsters; i++){
		for(int j=0;j<8;j++){
			if(single&&i!=select[mode]){
				fscanf(fp,"%c",&c);
				continue;
			}
			fscanf(fp,"%c",&(ClassData[i][j]));
		}
	}

	fclose(fp);
	sprintf(file,path);
}

void ImportClass(char *path){
	unsigned char r;
	FILE * fp = fopen(path,"rb");
	char in=0;

	fscanf(fp,"%c",&r);
	ClassNamesOffset = r;
	fscanf(fp,"%c",&r);
	ClassNamesOffset = ClassNamesOffset*256+r;
	fscanf(fp,"%c",&r);
	ClassNamesOffset = ClassNamesOffset*256+r;
	fscanf(fp,"%c",&r);
	ClassNamesOffset = ClassNamesOffset*256+r;

	int i;

	for(i=0; i<NumClasses; i++){
		fscanf(fp,"%c",&r);
		for(int j=0; j<r; j++){
			fscanf(fp,"%c",&(Classes[i][j]));
		}
		Classes[i][r]='\0';
	}

	fscanf(fp,"%c",&r);
	ClassOffset = r;
	fscanf(fp,"%c",&r);
	ClassOffset = ClassOffset*256+r;
	fscanf(fp,"%c",&r);
	ClassOffset = ClassOffset*256+r;
	fscanf(fp,"%c",&r);
	ClassOffset = ClassOffset*256+r;

	for(i=0; i<105; i++){
		for(int j=0;j<8;j++){
			fscanf(fp,"%c",&(ClassData[i][j]));
		}
	}

	fclose(fp);
}

void ClassImport(){
	int ret=IDYES;
	OPENFILENAME openFileName;
	char path[256];
	path[0] = '\0';    
	memset( &openFileName, 0, sizeof(openFileName) );
	openFileName.lStructSize = sizeof(openFileName);
	openFileName.hwndOwner = NULL;
	openFileName.hInstance = NULL;
	openFileName.lpstrFilter = "Shining Force Classes(*.sfcl)\0*.sfcl\0";
	openFileName.lpstrCustomFilter = NULL;
	openFileName.nMaxCustFilter = 0;
	openFileName.nFilterIndex = 0;
	openFileName.lpstrFile =  path;
	openFileName.nMaxFile = 256;
	openFileName.lpstrFileTitle = NULL;
	openFileName.nMaxFileTitle = 0;
	openFileName.lpstrInitialDir = ".";
	openFileName.lpstrTitle = NULL;
	openFileName.Flags = OFN_LONGNAMES | OFN_PATHMUSTEXIST;
	openFileName.nFileOffset = 0;
	openFileName.nFileExtension = 0;
	openFileName.lpstrDefExt = "sfcl";
	openFileName.lCustData = NULL;
	openFileName.lpfnHook = NULL;
	openFileName.lpTemplateName = NULL;

	if(GetOpenFileName(&openFileName)!=0){
		ImportClass(path);
	}
}