library ieee ;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity toplevel is
port (
LEDR : out std_logic_vector(9 downto 0);
LEDG : out std_logic_vector(7 downto 0);
SW : in std_logic_vector(9 downto 0)
);
end entity;
architecture behavioral of toplevel is
begin
    full_adder_4b_1 : entity work.full_adder_4b port map (
        a => SW(3 downto 0),
        b => SW(7 downto 4),
        cin => SW(9),
        s => LEDG(3 downto 0),
        cout => LEDG(7)
    );
	 LEDR(9) <= SW(9);
	 LEDR(3 downto 0) <= SW(3 downto 0);
	 LEDR(7 downto 4) <= SW(7 downto 4);
end architecture;