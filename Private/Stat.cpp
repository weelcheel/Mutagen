///////////////////////////////////////////////////////////
//  UStat.cpp
//  Implementation of the Class UStat
//  Created on:      04-May-2015 12:29:29
//  Original author: sam
///////////////////////////////////////////////////////////
#include "Mutagen.h"
#include "Stat.h"


UStat::UStat(){

}

double UStat::GetValue(){
	return value;
}


void UStat::SetValue(double newVal){
	value = newVal;
}


FString UStat::GetName(){
	return name;
}


void UStat::SetName(FString newVal){
	name = newVal;
}