/******************************************************************************
 *                       ____    _    _____                                   *
 *                      / ___|  / \  |  ___|    C++                           *
 *                     | |     / _ \ | |_       Actor                         *
 *                     | |___ / ___ \|  _|      Framework                     *
 *                      \____/_/   \_|_|                                      *
 *                                                                            *
 * Copyright 2011-2018 Dominik Charousset                                     *
 *                                                                            *
 * Distributed under the terms and conditions of the BSD 3-Clause License or  *
 * (at your option) under the terms and conditions of the Boost Software      *
 * License 1.0. See accompanying files LICENSE and LICENSE_ALTERNATIVE.       *
 *                                                                            *
 * If you did not receive a copy of the license files, see                    *
 * http://opensource.org/licenses/BSD-3-Clause and                            *
 * http://www.boost.org/LICENSE_1_0.txt.                                      *
 ******************************************************************************/

#include "caf/detail/try_match.hpp"

#include "caf/type_erased_tuple.hpp"

namespace caf::detail {

bool try_match(const type_erased_tuple& xs, const meta_element* iter,
               size_t ps) {
  if (xs.size() != ps)
    return false;
  for (size_t i = 0; i < ps; ++i, ++iter) {
    CAF_ASSERT(iter->typenr != 0 || iter->type != nullptr);
    if (xs.matches(i, iter->typenr, iter->type))
      return false;
  }
  return true;
}

} // namespace caf::detail
