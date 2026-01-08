/*
	Saya Mohammad Arya Dhinata dengan NIM 2504992 mengerjakan Tugas Masa Depan dalam 
	mata kuliah dasar-dasar pemrogaraman untuk keberkahanNya maka saya tidak melakukan
	kecurangan seperti yang di spesifikasikan. Aamin
*/

harus menambahkan spasi sebelum EOP.
batasnya 256 kata dan masing masing 65 karakter untuk pita.

|=======================================================================|
// test case

INSERT TabelPrimary.txt P009 Surya S004 N004 2187 #
INSERT SkillTable.txt S008 Sesepuh  #
INSERT NoteTable.txt N007 Wawawa #

UPDATE TabelPrimary.txt P009 UYa S004 N001 1269 #
UPDATE SkillTable.txt S008 SiSepuh  #
UPDATE NoteTable.txt N007 WiWeWo #

DELETE TabelPrimary.txt P009 #
DELETE SkillTable.txt S008 #
DELETE NoteTable.txt N007 #

SHOW TabelPrimary.txt #
SHOW SkillTable.txt #
SHOW NoteTable.txt #
SHOW TableComplete.txt #

|=======================================================================|

// salah query
JOIN all #

// memodifikasi file join (TableComplete.txt)
INSERT TableComplete.txt P009 Surya S004 N004 2187 #
UPDATE TableComplete.txt P009 Surya S001 N001 4236 #
DELETE TableComplete.txt P009 #

// ketika nama file salah
INSERT TabTab.txt P001 S004 N001 6315 #

// ketika file kosong

// ketika keynya sudah ada (untuk INSERT)
INSERT TabelPrimary.txt P004 Uya S005 N005 4217 #
INSERT SkillTable.txt S001 Sesepuh  #

// ketika keynya tidak ada (untuk UPDATE dan DELETE)
UPDATE TabelPrimary.txt P009 Surya S004 N004 2187 #
DELETE TabelPrimary.txt P009 #