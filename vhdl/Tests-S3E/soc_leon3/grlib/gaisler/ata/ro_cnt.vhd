---------------------------------------------------------------------
----                                                             ----
----  Run-Once Counter                                           ----
----                                                             ----
----  Author: Richard Herveille                                  ----
----          richard@asics.ws                                   ----
----          www.asics.ws                                       ----
----                                                             ----
---------------------------------------------------------------------
----                                                             ----
---- Copyright (C) 2001, 2002 Richard Herveille                  ----
----                          richard@asics.ws                   ----
----                                                             ----
---- This source file may be used and distributed without        ----
---- restriction provided that this copyright statement is not   ----
---- removed from the file and that any derivative work contains ----
---- the original copyright notice and the associated disclaimer.----
----                                                             ----
----     THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY     ----
---- EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED   ----
---- TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS   ----
---- FOR A PARTICULAR PURPOSE. IN NO EVENT SHALL THE AUTHOR      ----
---- OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,         ----
---- INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES    ----
---- (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE   ----
---- GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR        ----
---- BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  ----
---- LIABILITY, WHETHER IN  CONTRACT, STRICT LIABILITY, OR TORT  ----
---- (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  ----
---- OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE         ----
---- POSSIBILITY OF SUCH DAMAGE.                                 ----
----                                                             ----
---------------------------------------------------------------------

--
--  CVS Log
--
--  $Id: ro_cnt.vhd,v 1.1 2002/03/01 03:49:03 rherveille Exp $
--
--  $Date: 2002/03/01 03:49:03 $
--  $Revision: 1.1 $
--  $Author: rherveille $
--  $Locker:  $
--  $State: Exp $
--
-- Change History:
--               $Log: ro_cnt.vhd,v $
--               Revision 1.1  2002/03/01 03:49:03  rherveille
--               Changed internal counter libraries.
--               Split counter.vhd into separate files.
--               Core is in same state as Verilog version now.
--

library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;
library gaisler;

entity ro_cnt is
	generic(
		SIZE : natural := 8;
		UD   : integer := 0; -- default count down
		ID   : natural := 0      -- initial data after reset
	);
	port(
		clk    : in  std_logic;                  -- master clock
		nReset : in  std_logic := '1';           -- asynchronous active low reset
		rst    : in  std_logic := '0';           -- synchronous active high reset

		cnt_en : in  std_logic := '1';           -- count enable
		go     : in  std_logic;                  -- load counter and start sequence
		done   : out std_logic;                  -- done counting
		d      : in  std_logic_vector(SIZE -1 downto 0); -- load counter value
		q      : out std_logic_vector(SIZE -1 downto 0)  -- current counter value
	);
end entity ro_cnt;

architecture structural of ro_cnt is
	component ud_cnt is
	generic(
		SIZE : natural := 8;
		RESD : natural := 0      -- initial data after reset
	);
	port(
		clk    : in  std_logic;                  -- master clock
		nReset : in  std_logic := '1';           -- asynchronous active low reset
		rst    : in  std_logic := '0';           -- synchronous active high reset

		cnt_en : in  std_logic := '1';           -- count enable
		ud     : in  std_logic := '0';           -- up / not down
		nld    : in  std_logic := '1';           -- synchronous active low load
		d      : in  std_logic_vector(SIZE -1 downto 0); -- load counter value
		q      : out std_logic_vector(SIZE -1 downto 0); -- current counter value
		
		rci    : in  std_logic := '1';           -- carry input
		rco    : out std_logic                   -- carry output
	);
	end component ud_cnt;

	signal rci, rco, nld, UDP : std_logic;
begin
	gen_ctrl: process(clk, nReset)
	begin
		if (nReset = '0') then
			rci <= '0';
		elsif (clk'event and clk = '1') then
			if (rst = '1') then
				rci <= '0';
			else
				rci <= go or (rci and not rco);
			end if;
		end if;
	end process;

	nld <= not go;

        UDP <= '0' when UD = 0 else '1';
	-- hookup counter
	cnt : ud_cnt 
		generic map (
			SIZE => SIZE,
			RESD => ID
		)
		port map (
			clk => clk,
			nReset => nReset,
			rst => rst,
			cnt_en => cnt_en,
			ud => UDP,
			nld => nld,
			D => D,
			Q => Q, 
			rci => rci,
			rco => rco
		);

	done <= rco;
end architecture structural;
