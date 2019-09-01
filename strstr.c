/**
 * @input haystack : Read only ( DON'T MODIFY ) String termination by '\0'
 * @input needle : Read only ( DON'T MODIFY ) String termination by '\0'
 * 
 * @Output Integer
 */
int strStr(const char* haystack, const char* needle) {
	int lenh, lenn, i;
	lenh = strlen(haystack);
	lenn = strlen(needle);
	char temp[lenn];
	for (i = 0; i <= lenh-lenn; ++i)
	{
		strncpy(temp, haystack+i, lenn);
		if (!strcmp(temp, needle))
		{
			return i;
		}
	}
	return -1;
}
