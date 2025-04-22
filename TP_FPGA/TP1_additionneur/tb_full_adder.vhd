library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_full_adder is
end tb_full_adder;

architecture tb of tb_full_adder is
    signal a : std_logic := '0';
    signal b : std_logic := '0';
    signal cin : std_logic := '0';
    signal s : std_logic;
    signal c : std_logic;
begin
    UUT : entity work.FULL_ADDER port map (
        a => a,
        b => b,
        cin => cin,
        s => s,
        c => c
    );

    proc_inputs : process
    begin
        -- Test case 1: a=0, b=0, cin=0
        a <= '0';
        b <= '0';
        cin <= '0';
        wait for 50 ns;
        assert s = '0' report "Sum error in full adder (0 + 0 + 0)" severity error;
        assert c = '0' report "Carry error in full adder (0 + 0 + 0)" severity error;

        -- Test case 2: a=0, b=0, cin=1
        a <= '0';
        b <= '0';
        cin <= '1';
        wait for 50 ns;
        assert s = '1' report "Sum error in full adder (0 + 0 + 1)" severity error;
        assert c = '0' report "Carry error in full adder (0 + 0 + 1)" severity error;
        
        -- Test case 3: a=0, b=1, cin=0
        a <= '0';
        b <= '1';
        cin <= '0';
        wait for 50 ns;
        assert s = '1' report "Sum error in full adder (0 + 1 + 0)" severity error;
        assert c = '0' report "Carry error in full adder (0 + 1 + 0)" severity error;
        
        -- Test case 4: a=0, b=1, cin=1
        a <= '0';
        b <= '1';
        cin <= '1';
        wait for 50 ns;
        assert s = '0' report "Sum error in full adder (0 + 1 + 1)" severity error;
        assert c = '1' report "Carry error in full adder (0 + 1 + 1)" severity error;
        
        -- Test case 5: a=1, b=0, cin=0
        a <= '1';
        b <= '0';
        cin <= '0';
        wait for 50 ns;
        assert s = '1' report "Sum error in full adder (1 + 0 + 0)" severity error;
        assert c = '0' report "Carry error in full adder (1 + 0 + 0)" severity error;
        
        -- Test case 6: a=1, b=0, cin=1
        a <= '1';
        b <= '0';
        cin <= '1';
        wait for 50 ns;
        assert s = '0' report "Sum error in full adder (1 + 0 + 1)" severity error;
        assert c = '1' report "Carry error in full adder (1 + 0 + 1)" severity error;
        
        -- Test case 7: a=1, b=1, cin=0
        a <= '1';
        b <= '1';
        cin <= '0';
        wait for 50 ns;
        assert s = '0' report "Sum error in full adder (1 + 1 + 0)" severity error;
        assert c = '1' report "Carry error in full adder (1 + 1 + 0)" severity error;
        
        -- Test case 8: a=1, b=1, cin=1
        a <= '1';
        b <= '1';
        cin <= '1';
        wait for 50 ns;
        assert s = '1' report "Sum error in full adder (1 + 1 + 1)" severity error;
        assert c = '1' report "Carry error in full adder (1 + 1 + 1)" severity error;
        
        -- End of simulation
        wait;
    end process;
end tb;