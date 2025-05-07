Library ieee;
use ieee.std_logic_1164.all;
entity shift_register_universal8 is
port (
	-- Inputs
    SSR  : in  std_logic;                     -- Shift right serial input
    SSL  : in  std_logic;                     -- Shift left serial input
    Pi   : in  std_logic_vector(7 downto 0);  -- Parallel input
    SEL  : in  std_logic_vector(2 downto 0);  -- Mode selection
    CLK  : in  std_logic;                     -- Clock (rising edge sensitive)
    SETn : in  std_logic;                     -- Preset* (asynchronous, active low)
    RSTn : in  std_logic;                     -- Reset* (asynchronous, active low)
    
    -- Outputs
    SOR  : out std_logic;                     -- Shift output right
    SOL  : out std_logic;                     -- Shift output left
    Qo   : out std_logic_vector(7 downto 0)   -- Parallel outputs
);
end shift_register_universal8;


architecture behavioral of shift_register_universal8 is
	signal reg : std_logic_vector(7 downto 0);
begin
    -- Process for register operations
    process(CLK, RSTn, SETn)
    begin
        -- Asynchronous reset
        if RSTn = '0' then
            reg <= (others => '0');
        
        -- Asynchronous preset
        elsif SETn = '0' then
            reg <= (others => '1');
        
        -- Synchronous operations
        elsif rising_edge(CLK) then
            case SEL is
                -- Hold (memorize) - X00 (000 or 100)
                when "000" | "100" =>
                    reg <= reg;
                
                -- Shift right - 001
                when "001" =>
                    reg <= SSR & reg(7 downto 1);
                
                -- Shift left - 010
                when "010" =>
                    reg <= reg(6 downto 0) & SSL;
                
                -- Parallel load - X11 (011 or 111)
                when "011" | "111" =>
                    reg <= Pi;
                
                -- Rotate right - 101
                when "101" =>
                    reg <= reg(0) & reg(7 downto 1);
                
                -- Rotate left - 110
                when "110" =>
                    reg <= reg(6 downto 0) & reg(7);
                
                -- Default case (should not occur but handles all SEL values)
                when others =>
                    reg <= reg;
            end case;
        end if;
    end process;
    
    -- Continuous assignments for outputs
    Qo <= reg;                -- Parallel output
    SOR <= reg(0);           -- Shift output right (LSB)
    SOL <= reg(7);           -- Shift output left (MSB)
end behavioral;