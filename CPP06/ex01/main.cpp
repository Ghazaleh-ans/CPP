/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:39:10 by gansari           #+#    #+#             */
/*   Updated: 2026/02/11 15:04:32 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

void printData(const std::string& label, Data* data) {
	std::cout << label << std::endl;
	std::cout << "  Address: " << data << std::endl;
	std::cout << "  name:    " << data->name << std::endl;
	std::cout << "  age:     " << data->age << std::endl;
	std::cout << "  hasPet:  " << (data->hasPet ? "yes" : "no") << std::endl;
	std::cout << "  petName: " << data->petName << std::endl;
}

void test1_BasicSerialization() {
	std::cout << "\n=== Test 1: Basic Serialization ===" << std::endl;
	
	Data* original = new Data("Alice Johnson", 28, true, "Fluffy");
	std::cout << "\nOriginal:" << std::endl;
	printData("", original);
	
	uintptr_t serialized = Serializer::serialize(original);
	std::cout << "\nSerialized value (dec): " << serialized << std::endl;
	std::cout << "Serialized value (hex): 0x" << std::hex << serialized << std::dec << std::endl;
	
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "\nDeserialized:" << std::endl;
	printData("", deserialized);
	
	std::cout << "\nVerification:" << std::endl;
	std::cout << "  Pointers match: " << (original == deserialized ? "YES" : "NO") << std::endl;
	std::cout << "  Data matches:   " << (original->name == deserialized->name ? "YES" : "NO") << std::endl;
	
	delete original;
}

void test2_MultipleObjects() {
	std::cout << "\n=== Test 2: Multiple Objects ===" << std::endl;
	
	Data* data1 = new Data("Bob Smith", 35, false, "No pet");
	Data* data2 = new Data("Carol White", 42, true, "Max");
	Data* data3 = new Data("David Brown", 19, true, "Whiskers");
	
	std::cout << "\nOriginal objects:" << std::endl;
	std::cout << "  Data1: " << data1 << " - " << data1->name << std::endl;
	std::cout << "  Data2: " << data2 << " - " << data2->name << std::endl;
	std::cout << "  Data3: " << data3 << " - " << data3->name << std::endl;
	
	uintptr_t serial1 = Serializer::serialize(data1);
	uintptr_t serial2 = Serializer::serialize(data2);
	uintptr_t serial3 = Serializer::serialize(data3);
	
	std::cout << "\nSerialized values:" << std::endl;
	std::cout << "  Serial1 (dec): " << serial1 << std::endl;
	std::cout << "  Serial1 (hex): 0x" << std::hex << serial1 << std::dec << std::endl;
	std::cout << "  Serial2 (dec): " << serial2 << std::endl;
	std::cout << "  Serial2 (hex): 0x" << std::hex << serial2 << std::dec << std::endl;
	std::cout << "  Serial3 (dec): " << serial3 << std::endl;
	std::cout << "  Serial3 (hex): 0x" << std::hex << serial3 << std::dec << std::endl;
	
	Data* restored1 = Serializer::deserialize(serial1);
	Data* restored2 = Serializer::deserialize(serial2);
	Data* restored3 = Serializer::deserialize(serial3);
	
	std::cout << "\nVerification:" << std::endl;
	std::cout << "  Object 1 match: " << (data1 == restored1 ? "YES" : "NO") << std::endl;
	std::cout << "  Object 2 match: " << (data2 == restored2 ? "YES" : "NO") << std::endl;
	std::cout << "  Object 3 match: " << (data3 == restored3 ? "YES" : "NO") << std::endl;
	
	delete data1;
	delete data2;
	delete data3;
}

void test3_StackAndHeap() {
	std::cout << "\n=== Test 3: Stack vs Heap Objects ===" << std::endl;
	
	// Stack object
	Data stackData("Emily Davis", 31, true, "Shadow");
	Data* stackPtr = &stackData;
	
	std::cout << "\nStack object: " << stackPtr << std::endl;
	uintptr_t stackSerial = Serializer::serialize(stackPtr);
	std::cout << "  Serialized (dec): " << stackSerial << std::endl;
	std::cout << "  Serialized (hex): 0x" << std::hex << stackSerial << std::dec << std::endl;
	Data* stackRestored = Serializer::deserialize(stackSerial);
	std::cout << "  Match: " << (stackPtr == stackRestored ? "YES" : "NO") << std::endl;
	
	// Heap object
	Data* heapPtr = new Data("Frank Miller", 56, false, "No pet");
	std::cout << "\nHeap object: " << heapPtr << std::endl;
	uintptr_t heapSerial = Serializer::serialize(heapPtr);
	std::cout << "  Serialized (dec): " << heapSerial << std::endl;
	std::cout << "  Serialized (hex): 0x" << std::hex << heapSerial << std::dec << std::endl;
	Data* heapRestored = Serializer::deserialize(heapSerial);
	std::cout << "  Match: " << (heapPtr == heapRestored ? "YES" : "NO") << std::endl;
	
	delete heapPtr;
}

void test4_NullPointer() {
	std::cout << "\n=== Test 4: NULL Pointer ===" << std::endl;
	
	Data* nullPtr = NULL;
	uintptr_t nullSerial = Serializer::serialize(nullPtr);
	Data* nullRestored = Serializer::deserialize(nullSerial);
	
	std::cout << "\nNULL serialized (dec): " << nullSerial << std::endl;
	std::cout << "NULL serialized (hex): 0x" << std::hex << nullSerial << std::dec << std::endl;
	std::cout << "NULL deserialized:     " << nullRestored << std::endl;
	std::cout << "Match: " << (nullPtr == nullRestored ? "YES" : "NO") << std::endl;
}

void test5_ModifyThroughAlias() {
	std::cout << "\n=== Test 5: Modify Through Alias ===" << std::endl;
	
	Data* original = new Data("John Doe", 30, false, "No pet");
	uintptr_t serial = Serializer::serialize(original);
	Data* alias = Serializer::deserialize(serial);
	
	std::cout << "\nSerialized (dec): " << serial << std::endl;
	std::cout << "Serialized (hex): 0x" << std::hex << serial << std::dec << std::endl;
	
	std::cout << "\nBefore modification:" << std::endl;
	std::cout << "  Original name: " << original->name << std::endl;
	std::cout << "  Alias name:    " << alias->name << std::endl;
	
	alias->name = "Jane Doe";
	alias->hasPet = true;
	alias->petName = "Rex";
	
	std::cout << "\nAfter modifying alias:" << std::endl;
	std::cout << "  Original name: " << original->name << std::endl;
	std::cout << "  Original pet:  " << original->petName << std::endl;
	std::cout << "\nBoth point to same object: " << (original == alias ? "YES" : "NO") << std::endl;
	
	delete original;
}

int main() {
	std::cout << "CPP MODULE 06 - EXERCISE 01" << std::endl;
	std::cout << "Serialization Tests" << std::endl;
	std::cout << "===================" << std::endl;
	
	test1_BasicSerialization();
	test2_MultipleObjects();
	test3_StackAndHeap();
	test4_NullPointer();
	test5_ModifyThroughAlias();
	
	std::cout << "\n====================" << std::endl;
	std::cout << "All tests completed!" << std::endl;
	std::cout << "====================" << std::endl;
	
	return 0;
}