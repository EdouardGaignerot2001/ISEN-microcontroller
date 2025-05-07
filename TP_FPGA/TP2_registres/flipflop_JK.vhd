Library ieee;
use ieee.std_logic_1164.all;
-- flip flop JK (rising edge-triggered)
--
-- Symbol : Characteristic table :
--
--
--  +---------+    +---++----+-----+
--  |         |    | J || K  |  Q* |
-- -- J     Q--    +---++----+-----+
--  |         |    | 0 || 0  |  Q  |
-- --> K    Q*--   +---++----+-----+
--  |         |    | 0 || 1  |  0  |
--  +---------+    +---++----+-----+
--                 | 1 || 0  |  1  |
--                 +---++----+-----+
--                 | 1 || 1  | Q*  |
--                 +---++----+-----+
--
entity flipflop_JK is
port (
-- Inputs
J : in std_logic; -- J
CLK : in std_logic; -- CLK
K : in std_logic; -- K
-- Outputs
Q : out std_logic; -- Flip flop output
Qn : out std_logic -- Flip flop complemented output
);
end flipflop_JK;


architecture behavioral of flipflop_JK is
	signal Qinterne : std_logic := '0';
begin

process(CLK)
begin
if rising_edge(CLK) then
	if (J = '0' and K = '0') then
		 Qinterne <= Qinterne;        -- Maintien de l'état actuel
	elsif (J = '0' and K = '1') then
		 Qinterne <= '0';             -- Reset
	elsif (J = '1' and K = '0') then
		 Qinterne <= '1';             -- Set
	elsif (J = '1' and K = '1') then
		 Qinterne <= not Qinterne;    -- Toggle
	end if;
end if;
end process;

Q <= Qinterne;
Qn <= not Qinterne;

end behavioral;