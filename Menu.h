#pragma once
#include<iostream>
#include<Windows.h>
#include<string>
#include"point.h"
#include"KDtree.h"
#include <limits>
#include"Branch.h"
#include"HashMain.h"
#include"HashValley.h"
using namespace std;
extern KDtree pizzeria;
extern HashMain mainPizzeria;
extern HashValley Valley;
void AddP();
void AddBr();
void NearP();
void AvailP();
void Help();
void DelBr();
void ListBrs();
void AddN();
void Menu();
void NearBr();
void MostBrs();