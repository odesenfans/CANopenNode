/**
 * CANopen utilities.
 *
 * @file        CO_utils.h
 * @ingroup     CO_CANopen
 * @author      Janez Paternoster
 * @copyright   2004 - 2018 Janez Paternoster
 *
 * This file is part of CANopenNode, an opensource CANopen Stack.
 * Project home page is <https://github.com/CANopenNode/CANopenNode>.
 * For more information on CANopen see <http://www.can-cia.org/>.
 *
 * CANopenNode is free and open source software: you can redistribute
 * it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * Following clarification and special exception to the GNU General Public
 * License is included to the distribution terms of CANopenNode:
 *
 * Linking this library statically or dynamically with other modules is
 * making a combined work based on this library. Thus, the terms and
 * conditions of the GNU General Public License cover the whole combination.
 *
 * As a special exception, the copyright holders of this library give
 * you permission to link this library with independent modules to
 * produce an executable, regardless of the license terms of these
 * independent modules, and to copy and distribute the resulting
 * executable under terms of your choice, provided that you also meet,
 * for each linked independent module, the terms and conditions of the
 * license of that module. An independent module is a module which is
 * not derived from or based on this library. If you modify this
 * library, you may extend this exception to your version of the
 * library, but you are not obliged to do so. If you do not wish
 * to do so, delete this exception statement from your version.
 */


#ifndef CO_UTILS_H
#define CO_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * @brief Assumes that @p x is aligned with the specified @p alignment.
 *
 * Disables alignment warnings.
 *
 * @param[in]   x
 *              Pointer to check.
 * @param[in]   alignment
 *              Alignment requirement, in bytes.
 */
#define ASSUME_ALIGNED(x, alignment) __builtin_assume_aligned(x, alignment)

#ifdef __cplusplus
}
#endif /*__cplusplus*/

#endif /* CO_UTILS_H */
