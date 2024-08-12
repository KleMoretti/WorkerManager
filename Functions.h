//
// Created by 贾智超 on 2024/7/22.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <vector>
#include"WorkerClass.h"

void Exit();
void ReadInfo(std::vector<std::unique_ptr<Person>> &loadedObjects);
void SaveInfo(const std::vector<std::unique_ptr<Person>> &objects);
void AddInformation(std::vector<std::unique_ptr<Person>> &WInfo);
void ShowInformation(std::vector<std::unique_ptr<Person>> &loadedObjects);
void DeleteInformation(std::vector<std::unique_ptr<Person>> &Objects);
void ModifyInformation(std::vector<std::unique_ptr<Person>> &Objects);
void FindInformation();
void SortInformation();
void ClearAlltxt();
#endif //FUNCTIONS_H
