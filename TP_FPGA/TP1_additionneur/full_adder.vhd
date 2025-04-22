library ieee ;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
-- Full adder
entity FULL_ADDER is
port (
a : in std_logic;
b : in std_logic;
cin: in std_logic;
s : out std_logic;
c : out std_logic
);
end FULL_ADDER;
architecture behavioral of FULL_ADDER is
    signal s1 : std_logic;
    signal c1 : std_logic;
    signal c2 : std_logic;
begin
    half_adder_1 : entity work.HALF_ADDER port map (
        a => a,
        b => b,
        s => s1,
        c => c1
    );
	 
    half_adder_2 : entity work.HALF_ADDER port map (
        a => s1,
        b => cin,
        s => s,
        c => c2
    );
	 c <= c1 or c2;
end architecture;