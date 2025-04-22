library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity tb_full_adder_4b is
end tb_full_adder_4b;

architecture tb of tb_full_adder_4b is-- Inputs
    signal a : std_logic_vector(3 downto 0) := (others => '0');
    signal b : std_logic_vector(3 downto 0) := (others => '0');
    signal cin : std_logic := '0';
    
    -- Outputs
    signal s : std_logic_vector(3 downto 0);
    signal cout : std_logic;
begin
    UUT : entity work.full_adder_4b port map (
        a0 => a(0),
        b0 => b(0),
        a1 => a(1),
        b1 => b(1),
        a2 => a(2),
        b2 => b(2),
        a3 => a(3),
        b3 => b(3),
        cin => cin,
        s0 => s(0),
        s1 => s(1),
        s2 => s(2),
        s3 => s(3),
        cout => cout
    );

    proc_inputs : process
    begin
        -- Test case 1: 0 + 0 + 0
        a <= "0000";
        b <= "0000";
        cin <= '0';
        wait for 50 ns;
        assert s = "0000" report "Sum error in 4-bit adder (0 + 0 + 0)" severity error;
        assert cout = '0' report "Carry error in 4-bit adder (0 + 0 + 0)" severity error;

        -- Test case 2: 0 + 0 + 1
        a <= "0000";
        b <= "0000";
        cin <= '1';
        wait for 50 ns;
        assert s = "0001" report "Sum error in 4-bit adder (0 + 0 + 1)" severity error;
        assert cout = '0' report "Carry error in 4-bit adder (0 + 0 + 1)" severity error;
        
        -- Test case 3: 1 + 1 + 0
        a <= "0001";
        b <= "0001";
        cin <= '0';
        wait for 50 ns;
        assert s = "0010" report "Sum error in 4-bit adder (1 + 1 + 0)" severity error;
        assert cout = '0' report "Carry error in 4-bit adder (1 + 1 + 0)" severity error;
        
        -- Test case 4: Simple carry within bits
        a <= "0011";  -- 3
        b <= "0001";  -- 1
        cin <= '0';
        wait for 50 ns;
        assert s = "0100" report "Sum error in 4-bit adder (3 + 1 + 0)" severity error;
        assert cout = '0' report "Carry error in 4-bit adder (3 + 1 + 0)" severity error;
        
        -- Test case 5: Ripple carry through all bits
        a <= "1111";  -- 15
        b <= "0001";  -- 1
        cin <= '0';
        wait for 50 ns;
        assert s = "0000" report "Sum error in 4-bit adder (15 + 1 + 0)" severity error;
        assert cout = '1' report "Carry error in 4-bit adder (15 + 1 + 0)" severity error;
        
        -- Test case 6: Maximal addition with carry in
        a <= "1111";  -- 15
        b <= "1111";  -- 15
        cin <= '1';
        wait for 50 ns;
        assert s = "1111" report "Sum error in 4-bit adder (15 + 15 + 1)" severity error;
        assert cout = '1' report "Carry error in 4-bit adder (15 + 15 + 1)" severity error;
        
        -- Test case 7: Random test
        a <= "1010";  -- 10
        b <= "0101";  -- 5
        cin <= '0';
        wait for 50 ns;
        assert s = "1111" report "Sum error in 4-bit adder (10 + 5 + 0)" severity error;
        assert cout = '0' report "Carry error in 4-bit adder (10 + 5 + 0)" severity error;
        
        -- Test case 8: Random test with carry in
        a <= "1100";  -- 12
        b <= "0011";  -- 3
        cin <= '1';
        wait for 50 ns;
        assert s = "0000" report "Sum error in 4-bit adder (12 + 3 + 1)" severity error;
        assert cout = '1' report "Carry error in 4-bit adder (12 + 3 + 1)" severity error;
        
        -- End of simulation
        report "Test completed successfully";
        wait;
    end process;
end tb;