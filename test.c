struct node
{
	int id, filesize;
	struct (node*)child[20];
	node(int id, int size)
	{
		int i;
		this->id = id;
		this->filesize = size;
		for (i = 0; i < 20; i++)
		{
			child[i] = NULL;
		}
	}
};

int add(int id, int pid, int filesize)
{

}