#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define DEFAULT 3
#define DEFAULT_INC 2

typedef struct PeopInfo
{
	char name[10];
	char sex[4];
	char tele[10];

}PeopInfo;

typedef struct  Contact
{
	PeopInfo *date;//��¼�ÿ��ڴ��ַ��ָ��
	int capacity;//contact����
	int count;//��ǰ����
}Contact;

//��ʼ��
void InitContact(Contact* pc);

void Add(Contact* pc);

void Show(const Contact* pc);

void Modify(Contact* pc);

void Del(Contact* pc);

void Destory(Contact* pc);

void Save(const Contact* pc);

void Sort(Contact* pc);

int Findbyname(const Contact* pc, char name[]);

void LoadContact(Contact* pc);


