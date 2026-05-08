/**
 * @param {Object|Array} obj
 * @return {Object|Array}
 */

var compactObject = function(obj) {
    if (Array.isArray(obj)) {
        const result = []
        for (const item of obj) {
            const compacted = compactObject(item)
            if (Boolean(compacted)) result.push(compacted)
        }

        return result
    }

    if (obj !== null && typeof obj === "object") {
        const result = {}
        for (const key in obj) {
            const compacted = compactObject(obj[key])
            if (Boolean(compacted)) result[key] = compacted
        }

        return result
    }

    return obj
};