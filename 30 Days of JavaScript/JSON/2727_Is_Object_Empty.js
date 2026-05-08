/**
 * @param {Object|Array} obj
 * @return {boolean}
 */

var isEmpty = function(obj) {
    // Array or Object
    return Array.isArray(obj) ? obj.length == 0 : Object.keys(obj).length == 0
};