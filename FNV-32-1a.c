//FNV-32-1a.dll
//compile w/ cl:
// cl /c 02 FNV-32-1a.c
//link /DLL /OUT:FNV-32-1a.dll FNV-32-1a.obj
__declspec(dllexport) int __cdecl GetInfo(int buffer)
{
	char* buf = (char*)buffer;
	int* temp;
	temp = (int*)buf;
	*temp = 0x10000001;
	temp = (int*)(buf + 8);
	*temp = (int)buf;
	return buffer;
};

__declspec(dllexport) signed int __cdecl GetHash(int buffer)
{
	int buf = *(int*)(buffer + 8);
	int i = 0;
	unsigned int hval;
	int hash;
	for (hval = 0x811C9DC5;i < buf;i++)
	{
		hash = *(char*)(*(int*)(buffer + 4) + i);
		hval = (hash ^ hval) * 0x1000193;
	}
	*(char*)(*(int*)buffer) = hval >> 24;
	*(char*)(*(int*)buffer + 1) = hval >> 16;
	*(char*)(*(int*)buffer + 2) = hval >> 8;
	*(char*)(*(int*)buffer + 3) = hval;

	return 4;
};

