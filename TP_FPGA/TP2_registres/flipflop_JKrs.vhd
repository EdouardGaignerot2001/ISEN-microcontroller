Library ieee;
use ieee.std_logic_1164.all;
-- flip flop JK (rising edge-triggered) avec SET et RESET asynchrones
--
-- Symbol :                   Characteristic table :
--
--           SETn            Asynchronous behavior:
--            |
--  +---------+----+         +------+------+-------+
--  |              |         | SETn | RSTn |   Q   |
-- -- J          Q--         +------+------+-------+
--  |              |         |  0   |  1   |   1   | (Set priority)
-- --> K         Q*--        +------+------+-------+
--  |              |         |  1   |  0   |   0   | 
--  |              |         +------+------+-------+
--  +---------+----+         |  0   |  0   |   1   | (Set priority)
--            |              +------+------+-------+
--           RSTn            |  1   |  1   | See sync behavior |
--                           +------+------+-------+
--                            
--                           Synchronous behavior (when SETn=RSTn=1):
--                           +---+----+-----+
--                           | J | K  |  Q* |
--                           +---+----+-----+
--                           | 0 | 0  |  Q  |
--                           +---+----+-----+
--                           | 0 | 1  |  0  |
--                           +---+----+-----+
--                           | 1 | 0  |  1  |
--                           +---+----+-----+
--                           | 1 | 1  | ~Q  |
--                           +---+----+-----+
--
-- Note: SETn et RSTn sont actifs à l'état bas (active LOW)
--       SETn a priorité sur RSTn en cas d'activation simultanée
entity flipflop_JKrs is
port (
-- Inputs
J : in std_logic; -- J
CLK : in std_logic; -- CLK
K : in std_logic; -- K
RSTn : in std_logic;
SETn : in std_logic;
-- Outputs
Q : out std_logic; -- Flip flop output
Qn : out std_logic -- Flip flop complemented output
);
end flipflop_JKrs;


architecture behavioral of flipflop_JKrs is
	signal Qinterne : std_logic := '0';
begin

process(CLK, SETn, RSTn)
begin
if SETn = '0' then
	Qinterne <= '1';
elsif RSTn = '0' then
	Qinterne <= '0';
else
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
end if;


end process;

Q <= Qinterne;
Qn <= not Qinterne;

end behavioral;