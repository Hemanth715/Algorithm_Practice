#include<malloc.h>

typedef enum
{
	NAME,
	NUMBER,
	BIRTHDAY,
	EMAIL,
	MEMO
} FIELD;

typedef struct
{
	int count;
	char str[20];
} RESULT;

typedef struct Record{
	char name[20], number[20], birthday[20], email[20], memo[20];
	Record *next1, *next2, *next3, *next4, *next5;
	int active;
}Record;

Record **DB1, **DB2, **DB3, **DB4, **DB5;

void copy(char* a, char* b)
{
	int i;
	for (i = 0; i < 20; i++)
		a[i] = b[i];
}

Record* newNode(char* name, char* number, char *birthday, char* email, char* memo)
{
	Record *temp = (Record*)malloc(sizeof(Record));
	copy(temp->name, name);
	copy(temp->number, number);
	copy(temp->birthday, birthday);
	copy(temp->email, email);
	copy(temp->memo, memo);
	temp->next1 = NULL;
	temp->next2 = NULL;
	temp->next3 = NULL;
	temp->next4 = NULL;
	temp->next5 = NULL;
	temp->active = 1;
	return temp;
}

int hash_val(char* number)
{
	int i = 0, temp = 0;
	char c;
	while (number[i] != '\0')
	{
		c = number[i];
		temp += ((c - '0') * 7 + 22) % 107;
	}
	return (temp % 107);
}

void InitDB()
{
	DB1 = (Record**)malloc(107 * sizeof(Record*));
	DB2 = (Record**)malloc(107 * sizeof(Record*));
	DB3 = (Record**)malloc(107 * sizeof(Record*));
	DB4 = (Record**)malloc(107 * sizeof(Record*));
	DB5 = (Record**)malloc(107 * sizeof(Record*));
}

void Add(char* name, char* number, char *birthday, char* email, char* memo)
{
	Record *temp = newNode(name, number, birthday, email, memo);
	Record *temp1;
	temp1 = DB1[hash_val(name)];
	if (temp1 == NULL)
		temp1 = temp;
	else
	{
		while (temp1->next1 != NULL)
			temp1 = temp1->next1;
		temp1->next1 = temp;
	}
	temp1 = DB2[hash_val(number)];
	if (temp1 == NULL)
		temp1 = temp;
	else
	{
		while (temp1->next2 != NULL)
			temp1 = temp1->next2;
		temp1->next2 = temp;
	}
	temp1 = DB3[hash_val(birthday)];
	if (temp1 == NULL)
		temp1 = temp;
	else
	{
		while (temp1->next3 != NULL)
			temp1 = temp1->next3;
		temp1->next3 = temp;
	}
	temp1 = DB4[hash_val(email)];
	if (temp1 == NULL)
		temp1 = temp;
	else
	{
		while (temp1->next4 != NULL)
			temp1 = temp1->next4;
		temp1->next4 = temp;
	}
	temp1 = DB5[hash_val(memo)];
	if (temp1 == NULL)
		temp1 = temp;
	else
	{
		while (temp1->next5 != NULL)
			temp1 = temp1->next5;
		temp1->next5 = temp;
	}
	return;
}

int Delete(FIELD field, char* str)
{
	int count = 0;
	Record *temp;
	if (field == 1)
	{
		temp = DB1[hash_val(str)];
		while (temp != NULL)
		{
			if (temp->active == 1 && str == temp->name)
			{
				temp->active = 0;
				count++;
			}
			temp = temp->next1;
		}
		return count;
	}
	if (field == 2)
	{
		temp = DB2[hash_val(str)];
		while (temp != NULL)
		{
			if (temp->active == 1 && str == temp->number)
			{
				temp->active = 0;
				count++;
			}
			temp = temp->next2;
		}
		return count;
	}
	if (field == 3)
	{
		temp = DB3[hash_val(str)];
		while (temp != NULL)
		{
			if (temp->active == 1 && str == temp->birthday)
			{
				temp->active = 0;
				count++;
			}
			temp = temp->next3;
		}
		return count;
	}
	if (field == 4)
	{
		temp = DB4[hash_val(str)];
		while (temp != NULL)
		{
			if (temp->active == 1 && str == temp->email)
			{
				temp->active = 0;
				count++;
			}
			temp = temp->next4;
		}
		return count;
	}
	if (field == 5)
	{
		temp = DB5[hash_val(str)];
		while (temp != NULL)
		{
			if (temp->active == 1 && str == temp->memo)
			{
				temp->active = 0;
				count++;
			}
			temp = temp->next5;
		}
		return count;
	}
}

int Change(FIELD field, char *str, FIELD changefield, char* changestr)
{
	int count = 0;
	Record *temp, *temp1;
	if (field == 1)
	{
		temp = DB1[hash_val(str)];
		while (temp != NULL)
		{
			if (temp->active == 1 && str == temp->name)
			{
				switch (changefield){
				case 1:
					copy(temp->name, changestr);
					temp1 = DB1[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next1 != NULL)
							temp1 = temp1->next1;
						temp1->next1 = temp;
					}
					break;
				case 2:
					copy(temp->number, changestr);
					temp1 = DB2[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next2 != NULL)
							temp1 = temp1->next2;
						temp1->next2 = temp;
					}
					break;
				case 3:
					copy(temp->birthday, changestr);
					temp1 = DB3[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next3 != NULL)
							temp1 = temp1->next3;
						temp1->next3 = temp;
					}
					break;
				case 4:
					copy(temp->email, changestr);
					temp1 = DB4[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next4 != NULL)
							temp1 = temp1->next4;
						temp1->next4 = temp;
					}
					break;
				case 5:
					copy(temp->memo, changestr);
					temp1 = DB5[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next5 != NULL)
							temp1 = temp1->next5;
						temp1->next5 = temp;
					}
					break;
				}
				count++;
			}
			temp = temp->next1;
		}
		return count;
	}
	if (field == 2)
	{
		temp = DB2[hash_val(str)];
		while (temp != NULL)
		{
			if (temp->active == 1 && str == temp->number)
			{
				switch (changefield){
				case 1:
					copy(temp->name, changestr);
					temp1 = DB1[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next1 != NULL)
							temp1 = temp1->next1;
						temp1->next1 = temp;
					}
					break;
				case 2:
					copy(temp->number, changestr);
					temp1 = DB2[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next2 != NULL)
							temp1 = temp1->next2;
						temp1->next2 = temp;
					}
					break;
				case 3:
					copy(temp->birthday, changestr);
					temp1 = DB3[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next3 != NULL)
							temp1 = temp1->next3;
						temp1->next3 = temp;
					}
					break;
				case 4:
					copy(temp->email, changestr);
					temp1 = DB4[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next4 != NULL)
							temp1 = temp1->next4;
						temp1->next4 = temp;
					}
					break;
				case 5:
					copy(temp->memo, changestr);
					temp1 = DB5[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next5 != NULL)
							temp1 = temp1->next5;
						temp1->next5 = temp;
					}
					break;
				}
				count++;
			}
			temp = temp->next2;
		}
		return count;
	}
	if (field == 3)
	{
		temp = DB3[hash_val(str)];
		while (temp != NULL)
		{
			if (temp->active == 1 && str == temp->birthday)
			{
				switch (changefield){
				case 1:
					copy(temp->name, changestr);
					temp1 = DB1[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next1 != NULL)
							temp1 = temp1->next1;
						temp1->next1 = temp;
					}
					break;
				case 2:
					copy(temp->number, changestr);
					temp1 = DB2[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next2 != NULL)
							temp1 = temp1->next2;
						temp1->next2 = temp;
					}
					break;
				case 3:
					copy(temp->birthday, changestr);
					temp1 = DB3[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next3 != NULL)
							temp1 = temp1->next3;
						temp1->next3 = temp;
					}
					break;
				case 4:
					copy(temp->email, changestr);
					temp1 = DB4[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next4 != NULL)
							temp1 = temp1->next4;
						temp1->next4 = temp;
					}
					break;
				case 5:
					copy(temp->memo, changestr);
					temp1 = DB5[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next5 != NULL)
							temp1 = temp1->next5;
						temp1->next5 = temp;
					}
					break;
				}
				count++;
			}
			temp = temp->next3;
		}
		return count;
	}
	if (field == 4)
	{
		temp = DB4[hash_val(str)];
		while (temp != NULL)
		{
			if (temp->active == 1 && str == temp->email)
			{
				switch (changefield){
				case 1:
					copy(temp->name, changestr);
					temp1 = DB1[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next1 != NULL)
							temp1 = temp1->next1;
						temp1->next1 = temp;
					}
					break;
				case 2:
					copy(temp->number, changestr);
					temp1 = DB2[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next2 != NULL)
							temp1 = temp1->next2;
						temp1->next2 = temp;
					}
					break;
				case 3:
					copy(temp->birthday, changestr);
					temp1 = DB3[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next3 != NULL)
							temp1 = temp1->next3;
						temp1->next3 = temp;
					}
					break;
				case 4:
					copy(temp->email, changestr);
					temp1 = DB4[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next4 != NULL)
							temp1 = temp1->next4;
						temp1->next4 = temp;
					}
					break;
				case 5:
					copy(temp->memo, changestr);
					temp1 = DB5[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next5 != NULL)
							temp1 = temp1->next5;
						temp1->next5 = temp;
					}
					break;
				}
				count++;
			}
			temp = temp->next4;
		}
		return count;
	}
	if (field == 5)
	{
		temp = DB5[hash_val(str)];
		while (temp != NULL)
		{
			if (temp->active == 1 && str == temp->memo)
			{
				switch (changefield){
				case 1:
					copy(temp->name, changestr);
					temp1 = DB1[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next1 != NULL)
							temp1 = temp1->next1;
						temp1->next1 = temp;
					}
					break;
				case 2:
					copy(temp->number, changestr);
					temp1 = DB2[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next2 != NULL)
							temp1 = temp1->next2;
						temp1->next2 = temp;
					}
					break;
				case 3:
					copy(temp->birthday, changestr);
					temp1 = DB3[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next3 != NULL)
							temp1 = temp1->next3;
						temp1->next3 = temp;
					}
					break;
				case 4:
					copy(temp->email, changestr);
					temp1 = DB4[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next4 != NULL)
							temp1 = temp1->next4;
						temp1->next4 = temp;
					}
					break;
				case 5:
					copy(temp->memo, changestr);
					temp1 = DB5[hash_val(changestr)];
					if (temp1 == NULL)
						temp1 = temp;
					else
					{
						while (temp1->next5 != NULL)
							temp1 = temp1->next5;
						temp1->next5 = temp;
					}
					break;
				}
				count++;
			}
			temp = temp->next5;
		}
		return count;
	}
}

RESULT Search(FIELD field, char*str, FIELD returnfield)
{
	int count = 0;
	Record *temp;
	RESULT res;
	if (field == 1)
	{
		temp = DB1[hash_val(str)];
		while (temp != NULL)
		{
			if (temp->active == 1 && str == temp->name)
			{
				switch (returnfield){
				case 1:
					copy(res.str, temp->name);
					break;
				case 2:
					copy(res.str, temp->number);
					break;
				case 3:
					copy(res.str, temp->birthday);
					break;
				case 4:
					copy(res.str, temp->email);
					break;
				case 5:
					copy(res.str, temp->memo);
					break;
				}
				count++;
			}
			temp = temp->next1;
		}
		res.count = count;
		return res;
	}
	if (field == 2)
	{
		temp = DB2[hash_val(str)];
		while (temp != NULL)
		{
			if (temp->active == 1 && str == temp->number)
			{
				switch (returnfield){
				case 1:
					copy(res.str, temp->name);
					break;
				case 2:
					copy(res.str, temp->number);
					break;
				case 3:
					copy(res.str, temp->birthday);
					break;
				case 4:
					copy(res.str, temp->email);
					break;
				case 5:
					copy(res.str, temp->memo);
					break;
				}
				count++;
			}
			temp = temp->next2;
		}
		res.count = count;
		return res;
	}
	if (field == 3)
	{
		temp = DB3[hash_val(str)];
		while (temp != NULL)
		{
			if (temp->active == 1 && str == temp->birthday)
			{
				switch (returnfield){
				case 1:
					copy(res.str, temp->name);
					break;
				case 2:
					copy(res.str, temp->number);
					break;
				case 3:
					copy(res.str, temp->birthday);
					break;
				case 4:
					copy(res.str, temp->email);
					break;
				case 5:
					copy(res.str, temp->memo);
					break;
				}
				count++;
			}
			temp = temp->next3;
		}
		res.count = count;
		return res;
	}
	if (field == 4)
	{
		temp = DB4[hash_val(str)];
		while (temp != NULL)
		{
			if (temp->active == 1 && str == temp->email)
			{
				switch (returnfield){
				case 1:
					copy(res.str, temp->name);
					break;
				case 2:
					copy(res.str, temp->number);
					break;
				case 3:
					copy(res.str, temp->birthday);
					break;
				case 4:
					copy(res.str, temp->email);
					break;
				case 5:
					copy(res.str, temp->memo);
					break;
				}
				count++;
			}
			temp = temp->next4;
		}
		res.count = count;
		return res;
	}
	if (field == 5)
	{
		temp = DB5[hash_val(str)];
		while (temp != NULL)
		{
			if (temp->active == 1 && str == temp->memo)
			{
				switch (returnfield){
				case 1:
					copy(res.str, temp->name);
					break;
				case 2:
					copy(res.str, temp->number);
					break;
				case 3:
					copy(res.str, temp->birthday);
					break;
				case 4:
					copy(res.str, temp->email);
					break;
				case 5:
					copy(res.str, temp->memo);
					break;
				}
				count++;
			}
			temp = temp->next5;
		}
		res.count = count;
		return res;
	}
}