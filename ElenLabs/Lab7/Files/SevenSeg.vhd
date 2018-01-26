--Libreries
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

--Entity
ENTITY SevenSeg IS
	PORT (Number : IN STD_LOGIC_VECTOR (3 downto 0);
			OutputSevenSeg : OUT STD_LOGIC_VECTOR (6 downto 0));
	END SevenSeg;
	
--Architecture
ARCHITECTURE arc OF SevenSeg IS
	BEGIN
	P1: PROCESS (Number)
		BEGIN
		CASE Number IS
			WHEN "0000" =>
				OutputSevenSeg<="1000000";
			WHEN "0001" =>
				OutputSevenSeg<="1111001";
			WHEN "0010" =>
				OutputSevenSeg<="0100100";
			WHEN "0011" =>
				OutputSevenSeg<="0110000";	
			WHEN "0100" =>
				OutputSevenSeg<="0011001";
			WHEN "0101" =>
				OutputSevenSeg<="0010010";
			WHEN "0110" =>
				OutputSevenSeg<="0000010";
			WHEN "0111" =>
				OutputSevenSeg<="1111000";
			WHEN "1000" =>
				OutputSevenSeg<="0000000";
			WHEN "1001" =>
				OutputSevenSeg<="0010000";
			WHEN "1010" =>
				OutputSevenSeg<="0001000";	
			WHEN "1011" =>
				OutputSevenSeg<="0000011";		
			WHEN "1100" =>
				OutputSevenSeg<="1000110";	
			WHEN "1101" =>
				OutputSevenSeg<="0100001";	
			WHEN "1110" =>
				OutputSevenSeg<="0000110";
			WHEN "1111" =>
				OutputSevenSeg<="0001110";
			WHEN OTHERS=>NULL;
		END CASE;
	END PROCESS P1;	
										
	END arc;