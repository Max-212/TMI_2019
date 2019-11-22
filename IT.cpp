#include "IT.h";
#include <iostream>

using namespace IT;

IdTable IT::Create() {

	IdTable IdTable = {};
	IdTable.maxsize = TI_MAXSIZE;
	IdTable.size = 0;
	IdTable.table = new Entry[IdTable.maxsize];

	return IdTable;
}

void IT::Add(IdTable& idtable, Entry entry) {

	idtable.table[idtable.size] = entry;
	idtable.size++;
}

void IT::Delete(IdTable& idtable) {

	IdTable temp = {};
	idtable = temp;

}

Entry IT::GetEntry(IdTable &idtable, int n) {

	return idtable.table[n];
}


int IT::IsId(IdTable &idtable, char* id)
{
	 for (int i = idtable.size - 1; i >= 0; i--)
	 {
		if (strcmp(id, idtable.table[i].id) == 0)
		{
			return i;
		}
	 }
	 return TI_NULLIDX;
}


