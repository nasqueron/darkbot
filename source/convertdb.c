#include "defines.h"

#define STRING_SHORT    512
char DAT_DIR[STRING_SHORT] = { 0 };

// FIXME: This may not be compatible with putting all exes into $prefix/bin.
// Under cygwin the executable should be placed on Darkbot's root dir
// due to the necessity of cygwin dynamic library.  

int main(int argc, char *argv[])
{
    FILE *in, *out;
    char *ptr = NULL;
    const char *salt = "8fei3k";
    char userlist[STRING_SHORT] = { 0 };
    char tempfile[STRING_SHORT] = { 0 };
    char temp[STRING_SHORT] = { 0 };
    char channel[1024] = { 0 };
    char uh[1024] = { 0 };
    char level[10] = { 0 };
    char joins[10] = { 0 };
    char pass[1024] = { 0 };
    char setinfo[1024] = { 0 };
    struct stat st;
    int ret;

    printf("\nDarkbot USERLIST.DB < 7f0 conversion utility.\n");
    printf("IMPORTANT :: READ THIS!\n\n");
    printf("This UTILITY is for converting *OLD* (pre 7f0) userlist's\n");
    printf("to the new encrypted format.\n\n");
    printf("Use this utility ONLY if:\n");
    printf(" - You have copied your pre 7f0 userlist.db in to the dat directory\n\n");
    printf("DO NOT use this utility if:\n");
    printf(" - You have created a brand new darkbot, and have no users\n\n");

    if(argc < 2)
    {
        printf("Syntax: %s -convert\n\n", argv[0]);
        return 0;
    }

    if(argc > 1)
    {
        if(strcmp(argv[1], "-convert") != 0)
        {
            printf("Syntax: %s -convert\n\n", argv[0]);
            return 0;
        }
    }
    
#ifdef DATABASEDIR
	strncpy (DAT_DIR, DATABASEDIR, sizeof (DAT_DIR));
#else
	strncpy (DAT_DIR, "dat", sizeof (DAT_DIR));
#endif
#ifdef SOURCEDIR
	/* Check if this is being run from the build directory before being installed. */
	snprintf(temp, sizeof(temp), "%s/dat/setup.ini", SOURCEDIR);
	if (stat(temp, &st) >= 0)
	{
	    snprintf(temp, sizeof(temp), "%s/dat", SOURCEDIR);
	    strncpy(DAT_DIR, temp, sizeof (DAT_DIR));
	}
#endif

    snprintf(userlist, sizeof(userlist), "%s/userlist.db", DAT_DIR);
    snprintf(tempfile, sizeof(tempfile), "%s/temp.db", DAT_DIR);

    printf("Converting %s ...\n", userlist);

    if((in = fopen(userlist, "r")) == NULL)
    {
        printf("\nCan't open %s for reading!\n", userlist);
        return EXIT_FAILURE;
    }    if((out = fopen(tempfile, "wt")) == NULL)
    {
        printf("\nCan't open %s for writing!\n", tempfile);
        return EXIT_FAILURE;
    }

    snprintf(temp, sizeof(temp), "cp %s %s/backup.db", userlist, DAT_DIR);
    ret = system(temp);

    while(!feof(in))
    {
	ret =fscanf(in, "%s %s %s %s %s %[^\n]s", channel, uh, level, joins, pass, setinfo);

#ifdef ENABLE_ENCRYPT
        if ((ptr = crypt(pass, salt)) == NULL)
        {
            printf("\ncrypt() error\n");
            return EXIT_FAILURE;
        }
#endif
        if(!feof(in))
            fprintf(out, "%s %s %s %s %s %s\n", channel, uh, level, joins, ptr, setinfo);
    }
    fclose(in);
    fclose(out);

    remove(userlist);
    rename(tempfile, userlist);

    printf("Conversion Complete.\n");

    return EXIT_SUCCESS;
}
