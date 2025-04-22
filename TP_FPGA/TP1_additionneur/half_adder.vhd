library ieee ;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
-- Half adder
entity HALF_ADDER is
port (
a : in std_logic;
b : in std_logic;
s : out std_logic;
c : out std_logic
);
end HALF_ADDER;
architecture behavioral of HALF_ADDER is
	signal concat : std_logic_vector(1 downto 0);
begin
concat <= a & b;
with concat select
	s <= 	'1' when "01",
			'1' when "10",
			'0' when others;
with concat select
	c <= 	'1' when "11",
			'0' when others;
end architecture;