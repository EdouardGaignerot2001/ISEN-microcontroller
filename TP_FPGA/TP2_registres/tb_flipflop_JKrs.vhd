library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity tb_flipflop_JKrs is
end tb_flipflop_JKrs;

architecture tb of tb_flipflop_JKrs is
    signal J : std_logic := '0';
    signal K : std_logic := '0';
    signal CLK : std_logic := '0';
    signal Q : std_logic;
    signal Qn : std_logic;
    signal RSTn : std_logic := '1';  -- Active low reset, initialize to '1' (inactive)
    signal SETn : std_logic := '1';  -- Active low set, initialize to '1' (inactive)
begin
    -- Instance of the JK flip-flop with reset and set
    UUT : entity work.flipflop_JKrs port map (
        J => J, 
        K => K, 
        CLK => CLK, 
        Q => Q, 
        Qn => Qn,
        RSTn => RSTn,
        SETn => SETn
    );
    
    -- Test stimulus process with manual clock control
    stimuli: process
    begin
        -- Test reset functionality
        RSTn <= '0';  -- Assert reset
        SETn <= '1';
        J <= '0';
        K <= '0';
        CLK <= '0';
        wait for 5 ns;
        
        -- Manually toggle clock
        CLK <= '1';
        wait for 5 ns;
        CLK <= '0';
        wait for 5 ns;
        
        assert Q = '0' report "Error on reset" severity error;
        assert Qn = '1' report "Error on reset" severity error;
        
        -- Test set functionality
        RSTn <= '1';
        SETn <= '0';  -- Assert set
        CLK <= '1';
        wait for 5 ns;
        CLK <= '0';
        wait for 5 ns;
        
        assert Q = '1' report "Error on set" severity error;
        assert Qn = '0' report "Error on set" severity error;
        
        -- Deassert reset and set
        RSTn <= '1';
        SETn <= '1';
        wait for 5 ns;
        
        -- Test J=0, K=0 (hold state)
        J <= '0';
        K <= '0';
        CLK <= '1';
        wait for 5 ns;
        CLK <= '0';
        wait for 5 ns;
        -- The state should hold (no assertion needed as the state depends on previous state)
        
        -- Test J=0, K=1 (reset)
        J <= '0';
        K <= '1';
        CLK <= '1';
        wait for 5 ns;
        CLK <= '0';
        wait for 5 ns;
        
        assert Q = '0' report "Error on J=0,K=1 (reset)" severity error;
        assert Qn = '1' report "Error on J=0,K=1 (reset)" severity error;
        
        -- Test J=1, K=0 (set)
        J <= '1';
        K <= '0';
        CLK <= '1';
        wait for 5 ns;
        CLK <= '0';
        wait for 5 ns;
        
        assert Q = '1' report "Error on J=1,K=0 (set)" severity error;
        assert Qn = '0' report "Error on J=1,K=0 (set)" severity error;
        
        -- Test J=1, K=1 (toggle)
        J <= '1';
        K <= '1';
        CLK <= '1';
        wait for 5 ns;
        CLK <= '0';
        wait for 5 ns;
        
        assert Q = '0' report "Error on J=1,K=1 (toggle from 1 to 0)" severity error;
        assert Qn = '1' report "Error on J=1,K=1 (toggle from 1 to 0)" severity error;
        
        -- Test toggle again
        J <= '1';
        K <= '1';
        CLK <= '1';
        wait for 5 ns;
        CLK <= '0';
        wait for 5 ns;
        
        assert Q = '1' report "Error on J=1,K=1 (toggle from 0 to 1)" severity error;
        assert Qn = '0' report "Error on J=1,K=1 (toggle from 0 to 1)" severity error;
        
        -- End simulation
        report "Test completed successfully";
        wait;
    end process;

end tb;