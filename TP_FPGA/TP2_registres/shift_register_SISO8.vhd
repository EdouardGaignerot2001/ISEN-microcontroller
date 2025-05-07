Library ieee;
use ieee.std_logic_1164.all;
entity shift_register_SISO8 is
port (
-- Inputs
Si : in std_logic;
CLK : in std_logic;
RSTn : in std_logic;
SETn : in std_logic;
-- Outputs
So : out std_logic
);
end shift_register_SISO8;


architecture behavioral of shift_register_SISO8 is
	signal reg : std_logic_vector(7 downto 0);
begin
    process(CLK, RSTn, SETn)
    begin
        if RSTn = '0' then
            reg <= (others => '0');
        elsif SETn = '0' then
            reg <= (others => '1');
        elsif rising_edge(CLK) then
            reg <= Si & reg(7 downto 1);
        end if;
    end process;
    So <= reg(0);
end behavioral;