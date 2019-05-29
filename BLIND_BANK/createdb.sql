
SET SQL_MODE = 'NO_AUTO_VALUE_ON_ZERO';
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = '+00:00';


CREATE TABLE `grupy` (
  `idgrupy` int(11) NOT NULL,
  `Numer_Grupy` int(5) NOT NULL,
  `Informacje` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `grupy_uzytkownikow` (
  `idgrupy_uzytkownikow` int(11) NOT NULL,
  `iduzytkownika` varchar(45) NOT NULL,
  `idgrupy` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `Ocena` (
  `pk` int(11) NOT NULL,
  `id_osoby` int(11) NOT NULL,
  `id_pd` int(11) NOT NULL,
  `ocena` float DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

CREATE TABLE `pliki` (
  `pk` int(11) NOT NULL,
  `id_osoby` int(11) NOT NULL,
  `id_pd` int(11) NOT NULL,
  `nazwa` text COLLATE utf8_unicode_ci NOT NULL,
  `plik` longtext CHARACTER SET utf8 COLLATE utf8_polish_ci NOT NULL,
  `zatwierdzona` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

CREATE TABLE `praca_domowa` (
  `pk` int(11) NOT NULL,
  `id_grupy` int(11) NOT NULL,
  `title` varchar(50) CHARACTER SET utf8 COLLATE utf8_polish_ci NOT NULL,
  `contents` varchar(150) CHARACTER SET utf8 COLLATE utf8_polish_ci NOT NULL,
  `add_date` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `expire_date` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

CREATE TABLE `rola` (
  `idrola` int(11) NOT NULL,
  `Nazwa_Rola` varchar(45) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `rola` (`idrola`, `Nazwa_Rola`) VALUES
(1, 'Administrator'),
(2, 'Wykladowca'),
(3, 'Student');


CREATE TABLE `uzytkownicy` (
  `iduzytkownicy` int(11) NOT NULL,
  `Imie_Uzytkownika` varchar(45) NOT NULL,
  `Nazwisko_Uzytkownika` varchar(45) NOT NULL,
  `Unique_Index_Number` varchar(45) NOT NULL,
  `Email_Uzytkownika` varchar(45) NOT NULL,
  `Haslo_Uzytkownika` varchar(45) NOT NULL,
  `rola_idrola` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

ALTER TABLE `grupy`
  ADD PRIMARY KEY (`idgrupy`);

ALTER TABLE `grupy_uzytkownikow`
  ADD PRIMARY KEY (`idgrupy_uzytkownikow`);

ALTER TABLE `Ocena`
  ADD PRIMARY KEY (`pk`);

ALTER TABLE `pliki`
  ADD PRIMARY KEY (`pk`);

ALTER TABLE `praca_domowa`
  ADD PRIMARY KEY (`pk`);

ALTER TABLE `rola`
  ADD PRIMARY KEY (`idrola`);

ALTER TABLE `uzytkownicy`
  ADD PRIMARY KEY (`iduzytkownicy`,`rola_idrola`),
  ADD UNIQUE KEY `Unique_Index_Number_UNIQUE` (`Unique_Index_Number`),
  ADD KEY `fk_uzytkownicy_rola1_idx` (`rola_idrola`);

ALTER TABLE `grupy`
  MODIFY `idgrupy` int(11) NOT NULL AUTO_INCREMENT;

ALTER TABLE `grupy_uzytkownikow`
  MODIFY `idgrupy_uzytkownikow` int(11) NOT NULL AUTO_INCREMENT;

ALTER TABLE `Ocena`
  MODIFY `pk` int(11) NOT NULL AUTO_INCREMENT;

ALTER TABLE `pliki`
  MODIFY `pk` int(11) NOT NULL AUTO_INCREMENT;

ALTER TABLE `praca_domowa`
  MODIFY `pk` int(11) NOT NULL AUTO_INCREMENT;

ALTER TABLE `rola`
  MODIFY `idrola` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

ALTER TABLE `uzytkownicy`
  MODIFY `iduzytkownicy` int(11) NOT NULL AUTO_INCREMENT;

ALTER TABLE `uzytkownicy`
  ADD CONSTRAINT `fk_uzytkownicy_rola1` FOREIGN KEY (`rola_idrola`) REFERENCES `rola` (`idrola`);
COMMIT;

INSERT INTO `uzytkownicy`(`iduzytkownicy`, `Imie_Uzytkownika`, `Nazwisko_Uzytkownika`, `Unique_Index_Number`, `Email_Uzytkownika`, `Haslo_Uzytkownika`, `rola_idrola`) VALUES (null, 'root','root',0,'root@root.root','root',1)