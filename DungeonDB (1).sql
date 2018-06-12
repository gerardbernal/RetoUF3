-- phpMyAdmin SQL Dump
-- version 4.5.4.1deb2ubuntu2
-- http://www.phpmyadmin.net
--
-- Servidor: localhost
-- Tiempo de generación: 12-06-2018 a las 09:48:12
-- Versión del servidor: 5.7.22-0ubuntu0.16.04.1
-- Versión de PHP: 7.0.30-0ubuntu0.16.04.1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `DungeonDB`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `characters`
--

CREATE TABLE `characters` (
  `id_character` int(10) UNSIGNED NOT NULL,
  `character` varchar(32) NOT NULL,
  `races_id_race` int(10) UNSIGNED NOT NULL,
  `gold` int(10) UNSIGNED NOT NULL,
  `users_id_user` int(10) UNSIGNED NOT NULL,
  `level` int(10) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `characters`
--

INSERT INTO `characters` (`id_character`, `character`, `races_id_race`, `gold`, `users_id_user`, `level`) VALUES
(1, 'mamaduke', 4, 1000, 3, 99),
(2, 'mistertitan', 1, 100, 3, 60),
(3, 'pipo', 2, 32, 2, 30),
(4, 'cabe', 4, 10, 2, 40),
(5, 'zorvex', 3, 50, 1, 10),
(6, 'primo', 2, 0, 1, 1),
(7, 'hola', 2, 0, 1, 0),
(8, 'Papuko', 3, 0, 1, 1),
(9, 'pupuko', 2, 0, 1, 1),
(10, 'SementalDelCulo', 2, 0, 3, 1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `inventories`
--

CREATE TABLE `inventories` (
  `id_inventory` int(10) UNSIGNED NOT NULL,
  `characters_id_character` int(10) UNSIGNED NOT NULL,
  `objects_id_object` int(10) UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `inventories`
--

INSERT INTO `inventories` (`id_inventory`, `characters_id_character`, `objects_id_object`) VALUES
(1, 1, 1),
(2, 1, 2),
(3, 1, 3),
(4, 2, 1),
(5, 2, 4);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `maps`
--

CREATE TABLE `maps` (
  `id_map` int(10) UNSIGNED NOT NULL,
  `map` varchar(32) NOT NULL,
  `mapfile` text
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `maps`
--

INSERT INTO `maps` (`id_map`, `map`, `mapfile`) VALUES
(4, 'mapacompleto', '<Dungeon>\r\n   <sala id="0" celdas_h="960" celdas_v="960" pos_ini_h="0" pos_ini_v="0">\r\n       \r\n  <personaje name="Zelda" pos_h="96" pos_v="96"/>\r\n  \r\n  <obstaculos>\r\n    <obstaculo pos_h="640" pos_v="224" tipo="columna" />\r\n    <obstaculo pos_h="640" pos_v="224" tipo="barril" />    \r\n  </obstaculos>\r\n  <enemigos>\r\n    <enemigo pos_h="320" pos_v="320" tipo="orco"/>\r\n    <enemigo pos_h="160" pos_v="160" tipo="esqueleto"/>\r\n  </enemigos>\r\n  <objetos> \r\n    <objeto pos_h="288" pos_v="288" tipo="espada"/>\r\n    <objeto pos_h="224" pos_v="224" tipo="casco"/>\r\n  </objetos>\r\n  <tesoros>\r\n    <tesoro pos_h="640" pos_v="640" cantidad="100"/>\r\n    <tesoro pos_h="320" pos_v="32" cantidad="50"/>\r\n  </tesoros>\r\n  <puertas>\r\n    <puerta pos_h="928" pos_v="480" id="1"/>\r\n    <puerta pos_h="480" pos_v="928" id="2"/>\r\n  </puertas>\r\n    </sala>  \r\n    \r\n   <sala id="1" celdas_h="960" celdas_v="960" pos_ini_h="0" pos_ini_v="0">\r\n  \r\n  <personaje name="Zelda" pos_h="864" pos_v="96"/>\r\n\r\n  <obstaculos>\r\n    <obstaculo pos_h="672" pos_v="384" tipo="agujero" />    \r\n  </obstaculos>\r\n  <enemigos>\r\n    <enemigo pos_h="320" pos_v="192" tipo="elfo"/>\r\n    <enemigo pos_h="160" pos_v="160" tipo="fantasma"/>\r\n    <enemigo pos_h="256" pos_v="896" tipo="esqueleto"/>\r\n  </enemigos>\r\n  <objetos>\r\n    <objeto pos_h="288" pos_v="384" tipo="armadura"/>\r\n    <objeto pos_h="224" pos_v="224" tipo="arco"/>\r\n  </objetos>\r\n  <tesoros>\r\n    <tesoro pos_h="640" pos_v="640" cantidad="150"/>\r\n    <tesoro pos_h="320" pos_v="32" cantidad="80"/>\r\n  </tesoros>\r\n  <puertas>\r\n    <puerta pos_h="0" pos_v="480" id="0"/>\r\n  </puertas>\r\n  \r\n    </sala>  \r\n    \r\n    \r\n    <sala id="2" celdas_h="960" celdas_v="960" pos_ini_h="0" pos_ini_v="0">\r\n  \r\n  <personaje name="Zelda" pos_h="96" pos_v="96"/>\r\n\r\n  <obstaculos>\r\n    <obstaculo pos_h="192" pos_v="384" tipo="columna" />\r\n    <obstaculo pos_h="288" pos_v="480" tipo="barril" />    \r\n  </obstaculos>\r\n  <enemigos>\r\n    <enemigo pos_h="320" pos_v="288" tipo="orco"/>\r\n    <enemigo pos_h="640" pos_v="192" tipo="esqueleto"/>\r\n  </enemigos>\r\n  <objetos>\r\n    <objeto pos_h="224" pos_v="288" tipo="espada"/>\r\n    <objeto pos_h="288" pos_v="224" tipo="casco"/>\r\n  </objetos>\r\n  <tesoros>\r\n    <tesoro pos_h="320" pos_v="640" cantidad="74"/>\r\n    <tesoro pos_h="320" pos_v="64" cantidad="50"/>\r\n  </tesoros>\r\n  <puertas>\r\n    <puerta pos_h="480" pos_v="0" id="0"/>\r\n  </puertas>\r\n    </sala>  \r\n</Dungeon>');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `objects`
--

CREATE TABLE `objects` (
  `id_object` int(10) UNSIGNED NOT NULL,
  `object` varchar(64) NOT NULL,
  `protection` int(10) DEFAULT NULL,
  `damage` int(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `objects`
--

INSERT INTO `objects` (`id_object`, `object`, `protection`, `damage`) VALUES
(1, 'Helmet', 10, 0),
(2, 'Amor', 20, 0),
(3, 'Sword', 0, 15),
(4, 'Mace', 0, 20);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `races`
--

CREATE TABLE `races` (
  `id_race` int(10) UNSIGNED NOT NULL,
  `race` varchar(32) NOT NULL,
  `characteristic` varchar(32) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `races`
--

INSERT INTO `races` (`id_race`, `race`, `characteristic`) VALUES
(1, 'Human', 'Charisma'),
(2, 'Orc', 'Strenght'),
(3, 'Dark Elf', 'Intelligence'),
(4, 'Elf of the woods', 'Agility');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `users`
--

CREATE TABLE `users` (
  `id_user` int(10) UNSIGNED NOT NULL,
  `user` varchar(16) NOT NULL,
  `password` varchar(32) NOT NULL,
  `email` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Volcado de datos para la tabla `users`
--

INSERT INTO `users` (`id_user`, `user`, `password`, `email`) VALUES
(1, 'Joan', 'enti', 'Joan@enti.cat'),
(2, 'Gerard', 'enti', 'Gerard@enti.cat'),
(3, 'JC', 'enti', 'JC@enti.cat'),
(16, 'MIPRIMERITAVEZ', 'enti', 'mipremeritavez@gmail.com'),
(20, 'Zorvex', 'enti', 'zorvex@gmail.com'),
(25, 'SementalDelCulo', 'poni', 'jack@borderlands2.comxd');

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `characters`
--
ALTER TABLE `characters`
  ADD PRIMARY KEY (`id_character`),
  ADD KEY `races_id_race` (`races_id_race`),
  ADD KEY `users_id_user` (`users_id_user`);

--
-- Indices de la tabla `inventories`
--
ALTER TABLE `inventories`
  ADD PRIMARY KEY (`id_inventory`),
  ADD KEY `characters_id_character` (`characters_id_character`),
  ADD KEY `objects_id_object` (`objects_id_object`);

--
-- Indices de la tabla `maps`
--
ALTER TABLE `maps`
  ADD PRIMARY KEY (`id_map`);

--
-- Indices de la tabla `objects`
--
ALTER TABLE `objects`
  ADD PRIMARY KEY (`id_object`);

--
-- Indices de la tabla `races`
--
ALTER TABLE `races`
  ADD PRIMARY KEY (`id_race`);

--
-- Indices de la tabla `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id_user`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `characters`
--
ALTER TABLE `characters`
  MODIFY `id_character` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;
--
-- AUTO_INCREMENT de la tabla `inventories`
--
ALTER TABLE `inventories`
  MODIFY `id_inventory` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;
--
-- AUTO_INCREMENT de la tabla `maps`
--
ALTER TABLE `maps`
  MODIFY `id_map` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT de la tabla `objects`
--
ALTER TABLE `objects`
  MODIFY `id_object` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT de la tabla `races`
--
ALTER TABLE `races`
  MODIFY `id_race` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=5;
--
-- AUTO_INCREMENT de la tabla `users`
--
ALTER TABLE `users`
  MODIFY `id_user` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=26;
--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `characters`
--
ALTER TABLE `characters`
  ADD CONSTRAINT `characters_ibfk_1` FOREIGN KEY (`races_id_race`) REFERENCES `races` (`id_race`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `characters_ibfk_2` FOREIGN KEY (`users_id_user`) REFERENCES `users` (`id_user`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Filtros para la tabla `inventories`
--
ALTER TABLE `inventories`
  ADD CONSTRAINT `inventories_ibfk_1` FOREIGN KEY (`characters_id_character`) REFERENCES `characters` (`id_character`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `inventories_ibfk_2` FOREIGN KEY (`objects_id_object`) REFERENCES `objects` (`id_object`) ON DELETE CASCADE ON UPDATE CASCADE;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
