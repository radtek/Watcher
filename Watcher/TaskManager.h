#pragma once
#include <TlHelp32.h>

class TaskManager
{
	HANDLE _snapshot;
	std::vector<PROCESSENTRY32> _processes;
	std::map<DWORD, std::vector<MODULEENTRY32> > _modules;

	void CreateSnapshot(DWORD flags, DWORD pId);
	BOOL ProcessFirst(LPPROCESSENTRY32 pe) const;
	BOOL ProcessNext(LPPROCESSENTRY32 pe) const;
	BOOL ModuleFirst(LPMODULEENTRY32 me) const { return Module32First(_snapshot, me); }
	BOOL ModuleNext(LPMODULEENTRY32 me) const { return Module32Next(_snapshot, me); }
public:
	TaskManager(DWORD flags = TH32CS_SNAPPROCESS, DWORD pId = 0);
	~TaskManager();

	void GetActiveProcesses();
};

