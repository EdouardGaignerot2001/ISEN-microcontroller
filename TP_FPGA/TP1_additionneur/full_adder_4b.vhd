-- Copyright (C) 2025  Altera Corporation. All rights reserved.
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and any partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, the Altera Quartus Prime License Agreement,
-- the Altera IP License Agreement, or other applicable license
-- agreement, including, without limitation, that your use is for
-- the sole purpose of programming logic devices manufactured by
-- Altera and sold by Altera or its authorized distributors.  Please
-- refer to the Altera Software License Subscription Agreements 
-- on the Quartus Prime software download page.

-- PROGRAM		"Quartus Prime"
-- VERSION		"Version 24.1std.0 Build 1077 03/04/2025 SC Lite Edition"
-- CREATED		"Tue Apr 22 11:13:08 2025"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY full_adder_4b IS 
	PORT
	(
		a : IN std_logic_vector(3 downto 0);
		b : IN std_logic_vector(3 downto 0);
		s : OUT std_logic_vector(3 downto 0);
		cin :  IN  STD_LOGIC;
		cout :  OUT  STD_LOGIC
	);
END full_adder_4b;

ARCHITECTURE bdf_type OF full_adder_4b IS 

COMPONENT full_adder
	PORT(a : IN STD_LOGIC;
		 b : IN STD_LOGIC;
		 cin : IN STD_LOGIC;
		 s : OUT STD_LOGIC;
		 c : OUT STD_LOGIC
	);
END COMPONENT;

SIGNAL	SYNTHESIZED_WIRE_0 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_1 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_2 :  STD_LOGIC;


BEGIN 



b2v_inst : full_adder
PORT MAP(a => a(0),
		 b => b(0),
		 cin => cin,
		 s => s(0),
		 c => SYNTHESIZED_WIRE_0);


b2v_inst1 : full_adder
PORT MAP(a => a(1),
		 b => b(1),
		 cin => SYNTHESIZED_WIRE_0,
		 s => s(1),
		 c => SYNTHESIZED_WIRE_1);


b2v_inst2 : full_adder
PORT MAP(a => a(2),
		 b => b(2),
		 cin => SYNTHESIZED_WIRE_1,
		 s => s(2),
		 c => SYNTHESIZED_WIRE_2);


b2v_inst3 : full_adder
PORT MAP(a => a(3),
		 b => b(3),
		 cin => SYNTHESIZED_WIRE_2,
		 s => s(3),
		 c => cout);


END bdf_type;