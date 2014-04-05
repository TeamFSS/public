static char *shortcode;

void getscfromdb(char *scode)
{
	shortcode = scode;
}

char *getshortcodefromdb()
{
	return shortcode;
}
